
public interface IMessageService
{
    string GetMessage();
}

public class WelcomeMessageService : IMessageService
{
    public string GetMessage()
    {
        return "Hello I am Aadarsh Tamang!";
    }
}
