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
        var bytes = StringUtils.StringToByteArray(input);        
    }
}