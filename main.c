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
	char *pat = "+-*/%<>?:;=!", *chr;
	long c, hw = 0;
      	printf( ".intel_syntax noprefix\n" );
	printf( ".globl main\n" );
	printf( "main:\n" );
	for ( p ; *p ; p++ ) {
		if ( ( ( *p == '+' || *p == '-' ) && ( '0' <= *(p+1) && *(p+1) <= '9' ) ) || ( '0' <= *p && *p <= '9' ) ) {
			c = strtol( p, &p, 10 );
			putasm( "push %ld", c );
		} else if ( ( chr = strchr( pat, *p ) ) != NULL ) { 
			switch ( chr - pat ) {
			case 0:
				putasm( "pop rax" );
				putasm( "pop rbx" );
				putasm( "add rax, rbx" );
				putasm( "push rax" );
				break;
			case 1:
				putasm( "pop rax" );	
				putasm( "pop rbx" );
				putasm( "sub rax, rbx" );
				putasm( "push rax" );
				break;
			case 2:
				putasm( "pop rax" );
				putasm( "pop rdx" );
				putasm( "imul rdx" );
				putasm( "push rax" );
				break;
			case 3:
				putasm( "cqo" );
				putasm( "pop rax" );
				putasm( "pop rbx" );
				putasm( "idiv rbx" );
				putasm( "push rax" );
				break;
			case 4: // '%'
				putasm( "cqo" );	
				putasm( "pop rax" );
				putasm( "pop rbx" );
				putasm( "idiv rbx" );
				putasm( "push rdx" );
				break;
			case 5: // '<'
				putasm( "pop rax" );
				putasm( "pop rdi" );
				putasm( "cmp rax, rdi" );
				putasm( "setl al" );
				putasm( "movzb rax, al" );
				putasm( "push rax" );
				break;
			case 6: // '>'
				putasm( "pop rdi" );
				putasm( "pop rax" );
				putasm( "cmp rax, rdi" );
				putasm( "setl al" );
				putasm( "movzb rax, al" );
				putasm( "push rax" );
				break;
			case 7:
				hw += 1;
				putasm( "pop rax" );
				putasm( "cmp rax, 0" );
				putasm( "je .E%ld", hw );		
				break;
			case 8:
				putasm( "jmp .T%ld", hw );
				printf( ".E%ld:\n", hw );
				break;
			case 9:
				printf( ".T%ld:\n", hw );
				break;
			case 10:
				switch ( *(p+1) ) {
				case '=':			
					putasm( "pop rax" );
					putasm( "pop rdi" );
					putasm( "cmp rax, rdi" );
					putasm( "sete al" );
					putasm( "movzb rax, al" );
					putasm( "push rax" );
					break;
				case '<':
					putasm( "pop rax" );
					putasm( "pop rdi" );
					putasm( "cmp rax, rdi" );
					putasm( "setle al" );
					putasm( "movzb rax, al" );
					putasm( "push rax" );
					break;
				case '>':
					putasm( "pop rdi" );
					putasm( "pop rax" );
					putasm( "cmp rax, rdi" );
					putasm( "setl al" );
					putasm( "movzb rax, al" );
					putasm( "push rax" );
					break;
				}
				break;
			case 11:
				if ( *(p+1) == ' ' || *(p+1) == '\0' || *(p+1) == '\n' ) {
					putasm( "pop rax" );
					putasm( "not rax" );
					putasm( "push rax" );
				} else if ( *(p+1) == '=' ) {
					putasm( "pop rax" );
					putasm( "pop rdi" );
					putasm( "cmp rax, rdi" );
					putasm( "setne al" );
					putasm( "movzb rax, al" );
					putasm( "push rax" );
				}	
				break;
			}
		}
	}
	putasm( "pop rax" );
	putasm( "ret" );
	return 0;
}
