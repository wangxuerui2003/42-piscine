make

echo "---ONE FILE---"

echo "---c 5---"

tail -c 5  test1
echo
./ft_tail -c 5 test1

echo "---c5---"

tail -c5  test1
echo
./ft_tail -c5 test1

echo "---first_file_missing---"

tail -c5 a test1
echo
./ft_tail -c5 a test1

echo "---last_file_missing---"

tail -c5 test1 a
echo
./ft_tail -c5 test1 a

echo "---TWO FILE---"

echo "---c 5---"
tail -c 5  test1 test2
echo
./ft_tail -c 5 test1 test2

echo "---c5---"

tail -c5  test1 test2
echo
./ft_tail -c5 test1 test2

echo "---first_file_missing---"

tail -c5 a test1 test2
echo
./ft_tail -c5 a test1 test2

echo "---last_file_missing---"

tail -c5 test1 test2 a
echo
./ft_tail -c5 test1 test2 a

echo "---mid_file_missing---"

tail -c5 test1 a test2
echo
./ft_tail -c5 test1 a test2
