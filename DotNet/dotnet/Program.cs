using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using EmployeeApp.Data;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddControllersWithViews();

builder.Services.AddScoped<IMessageService, WelcomeMessageService>();

builder.Services.AddDbContext<ApplicationDbContext>(options =>
{
    options.UseSqlite(builder.Configuration.GetConnectionString("SQLiteConnection"));
        options.EnableSensitiveDataLogging(); // Enable if needed for debugging

});

// Add session services  

builder.Services.AddDistributedMemoryCache(); // For session state 
builder.Services.AddSession(options =>  
{  
    options.Cookie.Name = "MySessionCookie";     
    options.IdleTimeout = System.TimeSpan.FromMinutes(30);  
    options.Cookie.IsEssential = true;  
});  


var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}


app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseSession(); // Must be placed before UseRouting
app.UseRouting();

app.UseAuthorization();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");

app.Run();
