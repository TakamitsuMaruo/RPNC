#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "of.h"


int main( int argc, char *argv[] ) {
	if ( argc != 2 ) {
		printf( "ARGC is incorrect\n" );
		return 255;
	}
	char *p = argv[1];
	char *pat = "+-*/%<>?=!", *chr;
	long c;
      	printf( ".intel_syntax noprefix\n" );
	printf( ".globl main\n" );
	printf( "main:\n" );
	for ( p; *p; p++ ) {
		if ( ( ( *p == '+' || *p == '-' ) && ( '0' <= *(p+1) && *(p+1) <= '9' ) ) || ( '0' <= *p && *p <= '9'  ) ) {
			c = strtol( p, &p, 10 );
			putasm( "PUSH %ld", c );
		} else if ( ( chr = strchr( pat, *p ) ) != NULL ) { 
			switch ( chr - pat ) {
			case 0:
				putasm( "POP RAX" );
				putasm( "POP RBX" );
				putasm( "ADD RAX, RBX" );
				putasm( "PUSH RAX" );
				break;
			case 1:
				putasm( "POP RAX" );	
				putasm( "POP RBX" );
				putasm( "SUB RAX, RBX" );
				putasm( "PUSH RAX" );
				break;
			case 2:
				putasm( "POP RAX" );
				putasm( "POP RDX" );
				putasm( "IMUL RDX" );
				putasm( "PUSH RAX" );
				break;
			case 3:
				putasm( "CQO" );
				putasm( "POP RAX" );
				putasm( "POP RBX" );
				putasm( "IDIV RBX" );
				putasm( "PUSH RAX" );
				break;
			case 4: // '%'
				putasm( "CQO" );	
				putasm( "POP RAX" );
				putasm( "POP RBX" );
				putasm( "IDIV RBX" );
				putasm( "PUSH RDX" );
				break;
			case 5: // '<'
				putasm( "POP RAX" );
				putasm( "POP RDI" );
				putasm( "CMP RAX, RDI" );
				putasm( "SETL AL" );
				putasm( "MOVZB RAX, AL" );
				putasm( "PUSH RAX" );
				break;
			case 6: // '>'
				putasm( "POP RDI" );
				putasm( "POP RAX" );
				putasm( "CMP RAX, RDI" );
				putasm( "SETL AL" );
				putasm( "MOVZB RAX, AL" );
				putasm( "PUSH RAX" );
				break;
			case 7:
				break;
			case 8:
				switch ( *(p+1) ) {
				case '=':			
					putasm( "POP RAX" );
					putasm( "POP RDI" );
					putasm( "CMP RAX, RDI" );
					putasm( "SETE AL" );
					putasm( "MOVZB RAX, AL" );
					putasm( "PUSH RAX" );
					break;
				case '<':
					putasm( "POP RAX" );
					putasm( "POP RDI" );
					putasm( "CMP RAX, RDI" );
					putasm( "SETLE AL" );
					putasm( "MOVZB RAX, AL" );
					putasm( "PUSH RAX" );
					break;
				case '>':
					putasm( "POP RDI" );
					putasm( "POP RAX" );
					putasm( "CMP RAX, RDI" );
					putasm( "SETL AL" );
					putasm( "MOVZB RAX, AL" );
					putasm( "PUSH RAX" );
					break;
				}
				break;
			case 9:
				if ( *(p+1) == ' ' || *(p+1) == '\0' || *(p+1) == '\n' ) {
					putasm( "POP RAX" );
					putasm( "NOT RAX" );
					putasm( "PUSH RAX" );
				} else if ( *(p+1) == '=' ) {
					putasm( "POP RAX" );
					putasm( "POP RDI" );
					putasm( "CMP RAX, RDI" );
					putasm( "SETNE AL" );
					putasm( "MOVZB RAX, AL" );
					putasm( "PUSH RAX" );
				}	
				break;
			}
		}
	}
	putasm( "POP RAX" );
	putasm( "RET" );
	return 0;
}
