	
sort : exchange_sort.o merge_sort.o quick_sort.o heap_sort.o execution.o
	gcc -o sort exchange_sort.o merge_sort.o quick_sort.o heap_sort.o execution.o

exchange_sort.o : exchange_sort.c
	gcc -c -o exchange_sort.o exchange_sort.c
	
merge_sort.o : merge_sort.c
	gcc -c -o merge_sort.o merge_sort.c
	
quick_sort.o : quick_sort.c
	gcc -c -o quick_sort.o quick_sort.c
	
heap_sort.o : heap_sort.c
	gcc -c -o heap_sort.o heap_sort.c

execution.o : execution.c
	gcc -c -o execution.o execution.c

clean :
	rm *.o sort