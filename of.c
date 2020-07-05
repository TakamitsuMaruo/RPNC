#include "of.h"
#include <stdio.h>
#include <stdarg.h>

void putasm( const char *asmc,  ... ) {
	va_list ap;
	va_start( ap, asmc );
	printf( "\t" );
	vprintf( asmc, ap );
	printf( "\n" );
}
