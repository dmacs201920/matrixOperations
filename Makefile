project:main.o function.o f.o try.o
	gcc -o project main.o function.o f.o try.o
main.o:main.c
	gcc -c  main.c 
function.o:function.c 
	gcc -c  function.c  
f.o:f.c try.c
	gcc -c f.c try.c
try.o:try.c
	gcc -c try.c	
clean:
	rm -f *.s *.o *.c~

