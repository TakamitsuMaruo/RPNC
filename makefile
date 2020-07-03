rpnc: of.o main.c
	gcc -o rpnc of.o main.c

of: of.h of.c
	gcc -c of.h of.c
