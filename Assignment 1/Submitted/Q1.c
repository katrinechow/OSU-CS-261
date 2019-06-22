/* CS261- Assignment 1 - Q.1*/
/* Name: Katrine Chow
 * Date: April 15, 2018
 * Solution description: Implement functions to allocate, initialize, and sort
 * a collection of struct students.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student* sptr = malloc(10 * sizeof(struct student)); 
     /*return the pointer*/
	return sptr;
}

void generate(struct student* students){
     /*Generate random and unique ID and random scores for ten students, ID 
 	* being between 1 and 10, scores between 0 and 100*/

	/*Using Fisher-Yates Shuffle to swap randomized numbers*/
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int k;
	for(k = 9; k > 0; k--)
	{
	int j = rand() % 9;
	int n = rand() % 9;

	int temp;
	temp = array[j];
	array[j] = array[n];
	array[n] = temp;
	}
		

	int i;
	for(i = 0; i < 10; i++)
	{
		/*add unique id to student struct at position i*/
		students[i].id = array[i];

		/*generate random score for student i*/
		students[i].score = rand() % 100;
	}
				
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	int i;

	for(i = 0; i < 10; i++)
	{
		printf("ID %d, ", students[i].id);
		printf("Score %d\n", students[i].score);
	}
 
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int min;
	int max;
	int avg;
	int sum;

	int i;
	for (i = 0; i < 10; i++)
	{
		/*Searches for Max Score*/
		if(students[i].score > max)
		{
			max = students[i].score;
		}

		/*Searches for Min Score*/
		if(students[i].score < min)
		{
			min = students[i].score;
		}

		sum = sum + students[i].score;
	}

	avg = sum/10;

	printf("The minimum score is: %d\n", min);
	printf("The maximum score is: %d\n", max);
	printf("The average score is: %d\n", avg);
 
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	free(stud);
}

int main(){
    struct student* stud = NULL;

    /*call allocate*/
	stud = allocate();
 
    /*call generate*/
	generate(stud);
    
    /*call output*/
	output(stud);
    
    /*call summary*/
	summary(stud);
    
    /*call deallocate*/
	deallocate(stud);

    return 0;
}
