project:main.o function.o
	gcc -o project main.o function.o 
main.o:main.c header.h
	gcc -c  main.c header.h
function.o:function.c header.h
	gcc -c  function.c header.h
clean:
	rm -f *.s *.o

