test_binary=./encrepxor
input1="Burning 'em, if you ain't quick and nimble
I go crazy when I hear a cymbal"
input2="ICE"
expected_output="0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f"

actual_output=$($test_binary "$input1" $input2)

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
