using Microsoft.Data.Sqlite;
using System.Collections.Generic;

namespace CRUDApp.DataAccess
{
    public class EmployeeContext
    {
        private readonly string _connectionString;

        public EmployeeContext(string connectionString)
        {
            _connectionString = connectionString;
        }

        public IEnumerable<Employee> GetEmployees()
        {
            var employees = new List<Employee>();

            using (var connection = new SqliteConnection(_connectionString))
            {
                connection.Open();
                var command = connection.CreateCommand();
                command.CommandText = "SELECT Id, Name, Position, Salary FROM Employee";

                using (var reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        var employee = new Employee
                        {
                            Id = reader.GetInt32(0),
                            Name = reader.GetString(1),
                            Position = reader.GetString(2),
                            Salary = reader.GetFloat(3)
                        };
                        employees.Add(employee);
                    }
                }
            }

            return employees;
        }

        public Employee GetEmployeeById(int id)
        {
            Employee employee = null;

            using (var connection = new SqliteConnection(_connectionString))
            {
                connection.Open();
                var command = connection.CreateCommand();
                command.CommandText = "SELECT Id, Name, Position, Salary FROM Employee WHERE Id = @id";
                command.Parameters.AddWithValue("@id", id);

                using (var reader = command.ExecuteReader())
                {
                    if (reader.Read())
                    {
                        employee = new Employee
                        {
                            Id = reader.GetInt32(0),
                            Name = reader.GetString(1),
                            Position = reader.GetString(2),
                            Salary = reader.GetFloat(3)
                        };
                    }
                }
            }

            return employee;
        }

        public void AddEmployee(Employee employee)
        {
            using (var connection = new SqliteConnection(_connectionString))
            {
                connection.Open();

                // Set the busy timeout
                using (var command = connection.CreateCommand())
                {
                    command.CommandText = "PRAGMA busy_timeout = 3000"; // Timeout set to 3000 milliseconds
                    command.ExecuteNonQuery();
                }

                using (var transaction = connection.BeginTransaction())
                {
                    try
                    {
                        var command = connection.CreateCommand();
                        command.CommandText = "INSERT INTO Employee (Name, Position, Salary) VALUES (@name, @position, @salary)";
                        command.Parameters.AddWithValue("@name", employee.Name);
                        command.Parameters.AddWithValue("@position", employee.Position);
                        command.Parameters.AddWithValue("@salary", employee.Salary);

                        command.ExecuteNonQuery();
                        transaction.Commit();
                    }
                    catch (SqliteException ex) when (ex.SqliteErrorCode == 5)
                    {
                        // Handle SQLite locked error (retry logic or logging can be implemented here)
                        throw new Exception("Database is locked, please try again.", ex);
                    }
                    catch
                    {
                        transaction.Rollback();
                        throw;
                    }
                    finally
                    {
                        connection.Close();
                    }
                }
            }
        }


        public void UpdateEmployee(Employee employee)
        {
            using (var connection = new SqliteConnection(_connectionString))
            {
                connection.Open();
                var command = connection.CreateCommand();
                command.CommandText = "UPDATE Employee SET Name = @name, Position = @position, Salary = @salary WHERE Id = @id";
                command.Parameters.AddWithValue("@name", employee.Name);
                command.Parameters.AddWithValue("@position", employee.Position);
                command.Parameters.AddWithValue("@salary", employee.Salary);
                command.Parameters.AddWithValue("@id", employee.Id);

                command.ExecuteNonQuery();
            }
        }

        public void DeleteEmployee(int id)
        {
            using (var connection = new SqliteConnection(_connectionString))
            {
                connection.Open();
                var command = connection.CreateCommand();
                command.CommandText = "DELETE FROM Employee WHERE Id = @id";
                command.Parameters.AddWithValue("@id", id);

                command.ExecuteNonQuery();
            }
        }
    }
}

