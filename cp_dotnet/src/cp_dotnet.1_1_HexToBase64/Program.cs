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
        
        // read input as bytes
        var input = args[0];
        var inputBytes = StringUtils.StringToByteArray(input);

        // convert bytes to base64
        var base64 = Convert.ToBase64String(inputBytes);
    }
}