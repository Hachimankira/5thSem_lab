using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using dotnet.Models;

namespace dotnet.Controllers;

public class HomeController : Controller
{
    private readonly IMessageService _services;

    public HomeController(IMessageService services)
    {
        _services = services;
    }

    public IActionResult Index()
    {
        string message = _services.GetMessage();
        return View(model: message);
    }


    public IActionResult Privacy()
    {
        return View();
    }

    [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
    public IActionResult Error()
    {
        return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
    }
}
