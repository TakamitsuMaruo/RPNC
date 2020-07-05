ofs = of.h of.c
objfs = of.o

debug: $(ofs) main.c
	gcc $(objfs) -g -O0 -o rpnc main.c

release: $(ofs) main.c
	gcc $(objfs)    -O2 -o rpnc main.c

of: $(ofs)
	gcc -c $(ofs)


