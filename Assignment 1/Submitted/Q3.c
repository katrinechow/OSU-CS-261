/* CS261- Assignment 1 - Q.3*/
/* Name: Katrine Chow
 * Date: April 15, 2018
 * Solution description: We are sorting an array of struct students.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
	/*Algorithm referenced "Bubble Sort" at https://www.geeksforgeeks.org/
	 * bubble-sort/ */
	int index;
	int jdex;

	for(index = 0; index < n - 1; index++)
	{
		for(jdex = 0; jdex < n-index-1; jdex++)
		{
			if(students[jdex].score > students[jdex+1].score)
			{
				struct student temp;
				temp = students[jdex];
				students[jdex] = students[jdex+1];
				students[jdex+1] = temp;
			} 
		}
	}

}

int main(){


    /*Declare an integer n and assign it a value.*/
	int n;
	n = 20;

    /*Allocate memory for n students using malloc.*/
	struct student* sptr;
	sptr = malloc(n * sizeof(struct student));
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*
 */
	/*Using Fisher-Yates Shuffle to swap randomized numbers*/
	int array[n];

	/*Initialize array with n numbers*/
	int o;
	for(o = 0; o < n; o++)
	{
		array[o] = o+1;
	}


	int k;
	for(k = (n - 1); k > 0; k--)
	{
		int j = rand() % (n - 1);
		int x = rand() % (n - 1);

		int temp;
		temp = array[j];
		array[j] = array[x];
		array[x] = temp;
	}

	int i;
	for(i = 0; i < n; i++)
	{	
		/*add unique id to student struct at position i*/
		sptr[i].id = array[i];

		/*generate random score for student i*/
		sptr[i].score = rand() % 100;
 	}

	/*Print the contents of the array of n students.*/
	printf("Initial array:\n");

	int z;
	for (z = 0; z < n; z++)
	{
		printf("Student ID: %d, Score: %d\n", sptr[z].id, sptr[z].score);
	}

	printf("\n");

    /*Pass this array along with n to the sort() function*/
	sort(sptr, n);
    
    /*Print the contents of the array of n students.*/
	printf("Array after sorting:\n");

	int p;
	for (p = 0; p < n; p++)
	{
		printf("Student ID: %d , Score: %d\n", sptr[p].id, sptr[p].score);
	}

    /*Deallocating array*/
	free(sptr);
    
    return 0;
}
