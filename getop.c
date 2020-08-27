#include <stdio.h> 
#include <ctype.h> 
#include "calc.h"

int getop(char s[]) {
	int i, c;

	while ((s[0] = c = getchar()) == ' ' || c == '\t')
		; 
	s[1] = '\0'; if (!isdigit(c) && c != '.')
		return c;   /* not a number */ 
	i = 0; 
	if (isdigit(c)) 
		while (isdigit(s[++i] = c = getchar())); 
	if (c == '.') 
		while (isdigit(s[++i] = c = getchar())); 
	s[i] = '\0'; 
	if (c != EOF)
		ungetc(c, stdin); 
	return NUMBER;
}
