str_a=$1
str_b=$2

tmpfile1=$(mktemp)
tmpfile2=$(mktemp)

echo $str_a | xxd -p -b | sed -E 's/^.*: //g' | sed -E 's/  .*//g' > $tmpfile1
echo $str_b | xxd -p -b | sed -E 's/^.*: //g' | sed -E 's/  .*//g' > $tmpfile2

cat $tmpfile1
cat $tmpfile2

git diff --no-index --word-diff=color --word-diff-regex=. $tmpfile1 $tmpfile2
