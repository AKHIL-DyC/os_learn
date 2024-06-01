echo "enter two numbers :"
read a b
echo "a is $a and b is $b"
sum=$(expr $a + $b)
diff=$(expr $a - $b)
product=$(expr $a \* $b)
division=$(expr $a / $b)
echo "sum is $sum difference is $diff product is $product division is $division"

