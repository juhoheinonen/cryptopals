using System.Text;

namespace cp_dotnet.Utils;

public static class SingleByteXorCipher
{
    public static string Decrypt(string hexEncodedCipherText)
    {
        byte[] cipherBytes = Convert.FromHexString(hexEncodedCipherText);
        return Decrypt(cipherBytes);
    }

    public static string Decrypt(byte[] cipherBytes)
    {
        string decryptedText = string.Empty;
        int maxScore = 0;

        for (byte key = 0; key < byte.MaxValue; key++)
        {
            byte[] decryptedBytes = new byte[cipherBytes.Length];
            for (int i = 0; i < cipherBytes.Length; i++)
            {
                decryptedBytes[i] = (byte)(cipherBytes[i] ^ key);
            }

            string decryptedTextCandidate = Encoding.ASCII.GetString(decryptedBytes);
            int score = ScoreText(decryptedTextCandidate);

            if (score > maxScore)
            {
                maxScore = score;
                decryptedText = decryptedTextCandidate;
            }
        }

        return decryptedText;
    }

    private static int ScoreText(string text)
    {

        
        int score = 0;
        foreach (char c in text)
        {
            if (char.IsLetterOrDigit(c) || char.IsPunctuation(c) || char.IsWhiteSpace(c))
            {
                score++;
            }
            else
            {
                score--;
            }
        }

        return score;
    }
}