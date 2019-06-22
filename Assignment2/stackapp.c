/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */	
	assert(s != 0);

	DynArr* closeStack = newDynArr(256);

	while(*s != '\0')
	{
		char c = nextChar(s);

		if(c == '(')
		{
			pushDynArr(closeStack, ')');
		}
		else if (c == '{')
		{
			pushDynArr(closeStack, '}');
		}
		else if (c == '[')
		{
			pushDynArr(closeStack, ']');
		}

		if (c == ']' || c == '}' || c == ')')
		{
			TYPE temp = topDynArr(closeStack);
			if(temp == c)
			{
				popDynArr(closeStack);
			}
		}
	
		s++;	
	}
	
	if(isEmptyDynArr(closeStack))
	{
		deleteDynArr(closeStack);
		return 1;
	}	
	else
	{
		deleteDynArr(closeStack);
		return 0;
	}
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

