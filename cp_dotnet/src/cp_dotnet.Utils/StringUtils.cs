namespace cp_dotnet.Utils
{
    public static class StringUtils
    {        
        /// <summary>
        /// This solves Set 1 Challenge 2: Fixed XOR
        /// </summary>
        /// <param name="input1"></param>
        /// <param name="input2"></param>
        /// <returns></returns>
        public static byte[] FixedXor(string input1, string input2)
        {
            var bytes1 = Convert.FromHexString(input1);
            var bytes2 = Convert.FromHexString(input2);

            byte[] result = new byte[bytes1.Length];
            for (int i = 0; i < bytes1.Length; i++)
            {
                result[i] = (byte)(bytes1[i] ^ bytes2[i]);
            }

            return result;
        }

        /// <summary>
        /// This solves Set 1 Challenge 1: Convert hex to base64
        /// </summary>
        /// <param name="input"></param>
        /// <returns></returns>
        public static string HexStringToBase64(string input)
        {            
            var inputBytes = Convert.FromHexString(input); //  StringToByteArray(input);
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