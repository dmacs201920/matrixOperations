a.out:m.o f.o
	gcc m.o f.o -lm
m.o:m.c 
	gcc -c m.c
f.o:f.c 
	gcc -c f.c
