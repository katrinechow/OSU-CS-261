/* CS261- Assignment 1 - Q.4*/
/* Name: Katrine Chow
 * Date: April 15, 2018
 * Solution description: We are implementing functions that can parse a string
 * 			by omitting the underscore, and then print the string
 * 			in lower camel case.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}


void camelCase(char* word){
     /*Convert to camelCase*/

	int i;
	for(i = 0; i < 256; i++)
	{
		while(word[i] == '_')
		{
			if(word[i+1] >= 'a' && word[i+1] <= 'z')
			{
				word[i+1] = toUpperCase(word[i+1]);
			}

			int j;
			for (j = i; j < 256; j++)
			{
				word[j] = word[j+1];
			}
		}
	}
}

int main(){
    /*Read the string from the keyboard */
	printf("Enter a string:\n");
	
	/*Reading in string, referenced "fgets() and gets() in C language" from
 	*https://www.geeksforgeeks.org/fgets-gets-c-language/ 	*/

	char* input[256];
	fgets(input, sizeof(input), stdin);

    /*Call camelCase*/
	camelCase(input);
    
    /*Print the new the string */
	printf("The new string is: %s\n", input);
	
    
    return 0;
}
