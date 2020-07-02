#include "lst.h"

lst *new_lst( lst *st, long *head, size_t len ) {
	st->head = head;       
	st->tail = head;
	st->len = len;
	return st;
}

long pop( lst *st ) {
	long ret = *(st->tail);
	st->tail--;
	return ret;
}

long *push( lst *st, long val ) {
	if ( st->tail - st->head == sizeof( long ) * st->len )
       		return NULL;
	st->tail++;
	*(st->tail) = val;
	return st->tail;
}
		
