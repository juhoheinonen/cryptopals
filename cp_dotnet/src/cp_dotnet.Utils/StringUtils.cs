namespace cp_dotnet.Utils
{
    public static class StringUtils
    {
        public static byte[] StringToByteArray(string input)
        {
            byte[] bytes = new byte[input.Length / 2];
            for (int i = 0; i < input.Length; i += 2)
            {
                bytes[i / 2] = Convert.ToByte(input.Substring(i, 2), 16);
            }

            return bytes;
        }

        public static string StringToBase64(string input)
        {
            var inputBytes = StringToByteArray(input);
            return Convert.ToBase64String(inputBytes);
        }
    }
}