CC      := g++
CFLAGS  := -pedantic -Wall -Werror -g

all :  dlist_test calc call
	./dlist_test > dlist_test.out
	diff dlist_test.out.correct dlist_test.out
	./calc < calc.in > calc.out
	diff calc.out.correct calc.out
	./call < call.in > call.out
	diff call.out.correct call.out

dlist_test : dlist_test.cpp dlist.h
	$(CC) $(CFLAGS) dlist_test.cpp -o dlist_test

call : call.cpp dlist.h
	$(CC) $(CFLAGS) call.cpp -o call

calc : calc.cpp dlist.h
	$(CC) $(CFLAGS) calc.cpp -o calc

clean :
	rm -vf *.o *~ dlist_test calc call *.out
