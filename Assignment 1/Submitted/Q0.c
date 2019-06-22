/* CS261- Assignment 1 - Q.0*/
/* Name: Katrine Chow
 * Date: April 15, 2018
 * Solution description: We practice creating, initializing, and changing
 * 			pointers and the value it points to.
 */
 

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){

     /*Print the value of iptr*/
	printf("Value of iptr* is: %d\n", *iptr);     
     /*Print the address pointed to by iptr*/
	printf("Address point to by iptr* is: %p\n", iptr);
     /*Print the address of iptr itself*/
	printf("Address of iptr itself is: %p\n", &iptr);
     
     /*Change the value of iptr itself*/
        *iptr = 100; 
}

int main(){
    
    /*declare an integer x and initialize it randomly to a value in [0,10] */
	int x;
	x = rand() % 10;    
    /*Print the address of x*/
    	printf("The address of x is: %p\n", x);
    /*Call fooA() with the address of x*/
    	fooA(&x);
    /*Print the value of x*/
	printf("The value of x is: %d\n", x);
    /*Answer the question */
	/*The value of x should've been changed to 100 in fooA()*/	
    
    return 0;
   
    
}


