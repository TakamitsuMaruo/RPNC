#ifndef lst_h
#define lst_h

typedef struct lst lst;

struct lst {
	long *head;
	long *tail;
	size_t len;
};

lst *new_lst( lst *, long *, size_t );
long pop( lst * );
long *push( lst *, long );

#endif
