CC      := g++
CFLAGS  := -pedantic -Wall -Werror -g

all :  dlist_test dlist_test00 calc call
	./dlist_test > dlist_test.out
	diff dlist_test.out.correct dlist_test.out
	./calc < calc.in > calc.out
	diff calc.out.correct calc.out
	./call < call.in > call.out
	diff call.out.correct call.out
	./dlist_test00 > dlist_test00.out
	diff dlist_test00.out dlist_test00.out.correct
	./calc < calc2.in > calc2.out
	diff calc2.out.correct calc2.out
	./call < call2.in > call2.out
	diff call2.out.correct call2.out
	./call < call3.in > call3.out
	diff call3.out.correct call3.out

dlist_test : dlist_test.cpp dlist.h
	$(CC) $(CFLAGS) dlist_test.cpp -o dlist_test

call : call.cpp dlist.h
	$(CC) $(CFLAGS) call.cpp -o call

calc : calc.cpp dlist.h
	$(CC) $(CFLAGS) calc.cpp -o calc

dlist_test00 : dlist_test00.cpp dlist.h
	$(CC) $(CFLAGS) dlist_test00.cpp -o dlist_test00

calc2 : calc.cpp dlist.h
	$(CC) $(CFLAGS) calc.cpp -o calc

call2 : call.cpp dlist.h
	$(CC) $(CFLAGS) call.cpp -o call

call3 : call.cpp dlist.h
	$(CC) $(CFLAGS) call.cpp -o call

clean :
	rm -vf *.o *~ dlist_test calc call *.out
