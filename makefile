<<<<<<< HEAD
ofs = of.h of.c
objfs = of.o

debug: $(ofs) main.c
	gcc $(objfs) -g -O0 -o rpnc main.c

release: $(ofs) main.c
	gcc $(objfs)    -O2 -o rpnc main.c

of: $(ofs)
	gcc -c $(ofs)

=======
rpnc: of.o main.c
	gcc -o rpnc of.o main.c
>>>>>>> refs/remotes/origin/master

of: of.h of.c
	gcc -c of.h of.c
