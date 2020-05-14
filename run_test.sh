cp linkedlist.c linkedlist.h test
cd test
rm -rf *.o
gcc -c *.c
gcc -o run_test *.o
echo "Running tests"
echo "----------------------------------------------"
./run_test
echo "\n"
rm -rf *.o
rm linkedlist.c linkedlist.h
rm run_test
