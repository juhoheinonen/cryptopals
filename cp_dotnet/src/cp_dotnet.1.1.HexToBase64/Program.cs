using cp_dotnet.Utils;

class Program
{
    static void Main(string[] args)
    {
        if (args.Length != 1)
        {
            Console.WriteLine("Usage: HexToBase64 <hex_string>");
            return;
        }
        
        // read input
        var input = args[0];
        
        // convert bytes to base64
        string base64 = StringUtils.StringToBase64(input);

        System.Console.WriteLine(base64);
    }
}