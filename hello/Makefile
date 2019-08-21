libhello.o: libhello.c
	gcc -c libhello.c
hello: hello.c libhello.o
	gcc hello.c libhello.o -o hello
test: hello
	./hello Diego Oliver Javier

