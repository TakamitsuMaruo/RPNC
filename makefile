lsts = lst.h lst.c
ofs = of.h of.c
slibs = $(lsts) $(ofs)
objfs = lst.o of.o

rpnc: lst.o main.c
	gcc -o rpnc $(objfs) main.c

objs: $(slibs)
	gcc -include stddef.h -c $(lsts)
	gcc -c $(ofs)


