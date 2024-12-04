namespace cp_dotnet.Utils
{
    public static class StringUtils
    {
        /// <summary>
        /// This solves Set 1 Challenge 1: Convert hex to base64
        /// </summary>
        /// <param name="input"></param>
        /// <returns></returns>
        public static byte[] StringToByteArray(string input)
        {
            byte[] bytes = new byte[input.Length / 2];
            for (int i = 0; i < input.Length; i += 2)
            {
                bytes[i / 2] = Convert.ToByte(input.Substring(i, 2), 16);
            }

            return bytes;
        }       

        /// <summary>
        /// This solves Set 1 Challenge 2: Fixed XOR
        /// </summary>
        /// <param name="input1"></param>
        /// <param name="input2"></param>
        /// <returns></returns>
        public static byte[] FixedXor(string input1, string input2)
        {
            var bytes1 = StringToByteArray(input1);
            var bytes2 = StringToByteArray(input2);

            byte[] result = new byte[bytes1.Length];
            for (int i = 0; i < bytes1.Length; i++)
            {
                result[i] = (byte)(bytes1[i] ^ bytes2[i]);
            }

            return result;
        }

        /// <summary>
        /// Utility function to convert a string to a base64 string
        /// </summary>
        /// <param name="input"></param>
        /// <returns></returns>
        public static string StringToBase64(string input)
        {
            var inputBytes = StringToByteArray(input);
            return Convert.ToBase64String(inputBytes);
        }

        /// <summary>
        /// Utility function to convert a byte array to a string
        /// </summary>
        /// <param name="bytes"></param>
        /// <returns></returns>
        public static string ByteArrayToString(byte[] bytes)
        {
            return BitConverter.ToString(bytes).Replace("-", "").ToLower();
        }
    }
}