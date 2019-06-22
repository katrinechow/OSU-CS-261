/* CS261- Assignment 1 - Q.2*/
/* Name: Katrine Chow
 * Date: April 15, 2018
 * Solution description: For this assignment, we are filling in the function
 * foo() to perform requested tasks. 
 */
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /* Increment a */
	(*a)++;
    
    /* Decrement  b */
	(*b)--;
    
    /* Assign a+b to c */
	c = (*a) + (*b);
    
    /* Return c */
	return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
	int x = rand() % 10;
	int y = rand() % 10;
	int z = rand() % 10;

    /* Print the values of x, y and z */
	printf("The value of x is: %d\n", x);
	printf("The value of y is: %d\n", y); 
	printf("The value of z is: %d\n", z);
   
    /* Call foo() appropriately, passing x,y,z as parameters */
	int result;
	result = foo(&x, &y, z);
    
    /* Print the values of x, y and z */
	printf("The current value of x is: %d\n", x);
	printf("The current value of y is: %d\n", y);
	printf("The current value of z is: %d\n", z);
 
    /* Print the value returned by foo */
	 printf ("The value returned by foo is: %d\n", result);
    
    return 0;
}
    
    

