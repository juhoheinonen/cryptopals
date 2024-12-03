test_binary=./decr1bxor_multiple
input1=4.txt
expected_output="Possible cipher key: 5
Decrypted message: Now that the party is jumping

Score: -1.265855"
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
