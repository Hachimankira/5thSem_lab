using System;
using Microsoft.Data.Sqlite;

class Program
{
    private static string connectionString = "Data Source=products.db";

    static void Main()
    {
        CreateTable(); // Ensure the table is created
        // Example usage
        CreateProduct("Bike", 199.99m);
        ReadProducts();
        UpdateProduct(1, "Mountain Bike", 299.99m);
        DeleteProduct(1);
    }

    static void CreateTable()
    {
        using (var connection = new SqliteConnection(connectionString))
        {
            connection.Open();
            string createTableQuery = @"CREATE TABLE IF NOT EXISTS Products (
                                          Id INTEGER PRIMARY KEY AUTOINCREMENT,
                                          Name TEXT NOT NULL,
                                          Price REAL NOT NULL
                                        );";
            using (var command = new SqliteCommand(createTableQuery, connection))
            {
                command.ExecuteNonQuery();
            }
        }
    }

    static void CreateProduct(string name, decimal price)
    {
        using (var connection = new SqliteConnection(connectionString))
        {
            connection.Open();
            string sql = "INSERT INTO Products (Name, Price) VALUES (@Name, @Price)";
            using (var command = new SqliteCommand(sql, connection))
            {
                command.Parameters.AddWithValue("@Name", name);
                command.Parameters.AddWithValue("@Price", price);
                int rowsAffected = command.ExecuteNonQuery();
                Console.WriteLine($"{rowsAffected} row(s) inserted.");
            }
        }
    }

    static void ReadProducts()
    {
        using (var connection = new SqliteConnection(connectionString))
        {
            connection.Open();
            string sql = "SELECT * FROM Products";
            using (var command = new SqliteCommand(sql, connection))
            {
                using (var reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        Console.WriteLine($"ID: {reader["Id"]}, Name: {reader["Name"]}, Price: {reader["Price"]}");
                    }
                }
            }
        }
    }

    static void UpdateProduct(int id, string name, decimal price)
    {
        using (var connection = new SqliteConnection(connectionString))
        {
            connection.Open();
            string sql = "UPDATE Products SET Name = @Name, Price = @Price WHERE Id = @Id";
            using (var command = new SqliteCommand(sql, connection))
            {
                command.Parameters.AddWithValue("@Id", id);
                command.Parameters.AddWithValue("@Name", name);
                command.Parameters.AddWithValue("@Price", price);
                int rowsAffected = command.ExecuteNonQuery();
                Console.WriteLine($"{rowsAffected} row(s) updated.");
            }
        }
    }

    static void DeleteProduct(int id)
    {
        using (var connection = new SqliteConnection(connectionString))
        {
            connection.Open();
            string sql = "DELETE FROM Products WHERE Id = @Id";
            using (var command = new SqliteCommand(sql, connection))
            {
                command.Parameters.AddWithValue("@Id", id);
                int rowsAffected = command.ExecuteNonQuery();
                Console.WriteLine($"{rowsAffected} row(s) deleted.");
            }
        }
    }
}
