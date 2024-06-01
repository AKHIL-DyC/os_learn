echo "enter the number"
read n
c=$((n%2))
if [ $c -eq 0 ]
then 
    echo "even"
else
    echo "odd"
fi