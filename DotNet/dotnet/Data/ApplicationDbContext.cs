// Data/ApplicationDbContext.cs
using Microsoft.EntityFrameworkCore;
using EmployeeManagement.Models;
namespace EmployeeApp.Data
{
    public class ApplicationDbContext : DbContext
    {
        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
            : base(options)
        {
        }

        public DbSet<Employee>? Employees { get; set; }
    }

}
