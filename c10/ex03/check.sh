make re

echo '-- NO OPTION --'

hexdump test1 test2
echo
./ft_hexdump test1 test2

echo '-- LAST FILE MISSING --'
hexdump test1 test2 test3
echo
./ft_hexdump test1 test2 test3

echo '-- FIRST FILE MISSING --'
hexdump test3 test1 test2
echo
./ft_hexdump test3 test1 test2

echo '-- MID FILE MISSING --'
hexdump test1 test3 test2
echo
./ft_hexdump test1 test3 test2

echo '-- ALL FILE MISSING --'
hexdump test4 test5 test6
echo
./ft_hexdump test4 test5 test6

echo '-- OPTION --'

hexdump -C test1 test2
echo
./ft_hexdump -C test1 test2

echo '-- LAST FILE MISSING --'
hexdump -C test1 test2 test3
echo
./ft_hexdump -C test1 test2 test3

echo '-- FIRST FILE MISSING --'
hexdump -C test3 test1 test2
echo
./ft_hexdump -C test3 test1 test2

echo '-- MID FILE MISSING --'
hexdump -C test1 test3 test2
echo
./ft_hexdump -C test1 test3 test2

echo '-- ALL FILE MISSING --'
hexdump -C test4 test5 test6
echo
./ft_hexdump -C test4 test5 test6
