all: sem.c
	gcc -o control sem.c
run: all
	./control -c 4
	./control -c 3
	./control -c 2
	./control -v
	./control -r 
