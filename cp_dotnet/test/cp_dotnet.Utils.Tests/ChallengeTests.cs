using Xunit;

namespace cp_dotnet.Utils.Tests
{
    [TestClass]
    public class ChallengeTests
    {
        [TestMethod]
        public void TestChallenge()
        {
            // Arrange
            var challenge = new Challenge();

            // Act
            var result = challenge.GetChallenge();

            // Assert
            Assert.AreEqual("Hello World!", result);
        }
    }
}