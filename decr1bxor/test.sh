test_binary=./decr1bxor
input1=1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736
expected_output="Possible cipher key: X
Cooking MC's like a pound of bacon
436f6f6b696e67204d432773206c696b65206120706f756e64206f66206261636f6e"
actual_output=$($test_binary $input1)

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No color

if test "$expected_output" = "$actual_output"
then
	echo -e "${GREEN}Test passed!${NC}"
else
	echo -e "${RED}Test failed.${NC}"
	echo "Expected: $expected_output."
	echo "Actual  : $actual_output."
fi
