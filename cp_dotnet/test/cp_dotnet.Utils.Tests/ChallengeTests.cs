namespace cp_dotnet.Utils.Tests
{
    public class ChallengeTests
    {
        [Fact]
        public void Set1_1_HexToBase64()
        {
            // Arrange
            var input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";

            // Act
            var result = StringUtils.HexStringToBase64(input);

            // Assert
            Assert.Equal("SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t", result);
        }

        [Fact]
        public void Set1_2_FixedXor()
        {
            // Arrange
            var input1 = "1c0111001f010100061a024b53535009181c";
            var input2 = "686974207468652062756c6c277320657965";

            // Act
            var result = StringUtils.FixedXor(input1, input2);            

            // Assert
            Assert.Equal("746865206b696420646f6e277420706c6179", result);
        }

        [Fact]
        public void Set1_3_SingleByteXorCipher()
        {
            // Arrange
            var input = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

            // Act
            var result = SingleByteXorCipher.Decrypt(input);

            // Assert
            Assert.Equal("Cooking MC's like a pound of bacon", result);
        }
    }
}