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
            var result = StringUtils.StringToBase64(input);

            // Assert
            Assert.Equal("SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t", result);
        }
    }
}