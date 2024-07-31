using Microsoft.AspNetCore.Mvc;
namespace State.Controllers

{
    public class StateController : Controller
    {
        public IActionResult Add()
        {
            return View();
        }
        [HttpPost]
        public IActionResult SetUserData(string username, string message)
        {
            HttpContext.Session.SetString("Username", username);
            TempData["Message"] = message;
            return RedirectToAction("Display");
        }
        public IActionResult Display()
        {
            string username = HttpContext.Session.GetString("Username");
            string message = TempData["Message"] as string;
            ViewBag.Username = username;
            ViewBag.Message = message;
            return View();
        }

        // client side state management

        public IActionResult Index()  
        {  
            return View();  
        }  
        [HttpPost]  
        public IActionResult SetCookie(string data)  
        {  
            // Set a cookie with the user-provided data             
            CookieOptions option = new CookieOptions();  
            option.Expires = DateTime.Now.AddMinutes(30); // Cookie expiration time  
            Response.Cookies.Append("UserData", data, option);             
            return RedirectToAction("Index");  
        }  
        public IActionResult GetCookie()  
        {  
            // Retrieve the user data from the cookie             
            string userData = Request.Cookies["UserData"];  
            ViewBag.UserData = userData;  
            return View();  
        }  
    }
}