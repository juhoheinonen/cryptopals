test_binary=./xorhexstrings
input1=1c0111001f010100061a024b53535009181c 
input2=686974207468652062756c6c277320657965
expected_output=746865206b696420646f6e277420706c6179
actual_output=$($test_binary $input1 $input2)

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
