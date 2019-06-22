/*
 * This is the file in which you'll write the functions required to 
implement
 * a stack using two queues.  Make sure to add your name and 
@oregonstate.edu
 * email address below:
 *
 * Name: Katrine Chow 
 * Email: chowk@oregonstate.edu
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


#ifndef TYPE
#define TYPE int
#endif

/**************************************************
 All of the initial Queue functions
 ***************************************************/
struct link {
	TYPE value;
	struct link * next;
};

struct listQueue {
	struct link *firstLink;
	struct link *lastLink;
	int size;
};

/*
* This function takes a queue and allocates the memory. It then
* creates a sentinel and assigns the first link and last link
* to the sentinel.
*/
void listQueueInit(struct listQueue *q) {
	
       // FIXME: you must write this
       struct link* newLink = malloc(sizeof(struct link));
	assert(newLink != 0);

	newLink->next = 0;
	q->firstLink = newLink;
	q->lastLink = newLink;	

}

/*
 * This function creates a new queue. Parts of the create include 
allocating
 * the memory, initializing all of the values and returning a pointer to 
the newly
 * created queue.
 */
struct listQueue * listQueueCreate()
{
     //FIXME: you must write this
	struct listQueue* q = malloc(sizeof(struct listQueue));
	listQueueInit(q);
	return q;
	
}


/*
* This function returns a 1 or 0 based on the statement looking at
* the first link. If the next value is null it is empty, and will return 1
*/
int listQueueIsEmpty(struct listQueue *q) {
	
          //FIXME: you must write this
	if(q->firstLink->next == 0)
	{
		return 1;
	}

	return 0;

}

/*
 * This function adds a new link and value to the back of the queue. It 
takes
 * a list and a type variable, allocates the memory and adjusts the proper 
links
 * to make the connection. No return value.
 */
void listQueueAddBack(struct listQueue *q, TYPE e) {
	

       // FIXME: you must write this
	assert(!listQueueIsEmpty(q));

	struct link* temp = malloc(sizeof(struct link));
	temp->value = e;

	q->lastLink->next = temp;
	temp->next = NULL;
	q->lastLink = temp;

	q->size++;


}

/*
 * This function takes a list argument and removes the link at the front.
 */
void listQueueRemoveFront(struct listQueue *q) {

    
    // FIXME: you must write this
	assert(!listQueueIsEmpty(q));

	struct link* temp = q->firstLink;
	q->firstLink = q->firstLink->next;
	q->firstLink->next = q->firstLink;

	free(temp);

	q->size--;


}

/*
 * Function returns the value at the front of the list.
 */
TYPE listQueueFront(struct listQueue *q) {
	
       // FIXME: you must write this
       return q->firstLink->next->value;

}


/*
* This function is a tester function that iterates through the list
* and prints out the values at each link.
*/
void printList(struct listQueue* l)
{
	assert(l != 0);
	
	struct link * printMe = l->firstLink->next;

	while (printMe!= NULL)
	{
		printf("Value: %d\n", printMe->value);
		printMe = printMe->next;
	}
}

/**************************************************
Stack Implementation
***************************************************/

struct linkedListStack {
	struct listQueue *Q1;
	struct listQueue *Q2;
	int structSize;
};

/*
 * This function initializes the values of the created Stack. Initializes 
both 
 * queues and the structSize.
 */
void linkedListStackInit(struct linkedListStack * s)
{
	// FIXME: you must write this
	s->Q1 = listQueueCreate();
	s->Q2 = listQueueCreate();

	s->structSize = 0;

 }

/*
* This function creates the linked list stack. It allocates the memory and 
calls the
* initialization function to initialize all of the values. It then returns 
the stack.
*/
struct linkedListStack * linkedListStackCreate(){

    // FIXME: you must write this
	struct linkedListStack* st = malloc(sizeof(struct linkedListStack));
	linkedListStackInit(st);
	return st;


}

/*
* This function returns 1 if the linked list stack is empty and otherwise 
returns a 0.
*/
int linkedListStackIsEmpty(struct linkedListStack *s) {

	// FIXME: you must write this
	if(s->Q1->firstLink->next == NULL && s->Q2->firstLink->next == NULL)
	{
		return 1;
	}
	
	return 0;
}

/*
 * This is the linked list acting as a stack push function. It takes 
 * a linked list stack argument and a value and pushes it onto the stack. 
The
 * funciton then also increases the size of the stack by 1. 
 */
void linkedListStackPush(struct linkedListStack *s, TYPE d) {
	
        // FIXME: you must write this
        assert(!linkedListStackIsEmpty(s));

	struct link* temp = malloc(sizeof(struct link));
	temp->value = d;

	temp = s->Q1->lastLink->next;
	s->Q1->lastLink->next = temp;
	s->Q1->lastLink = temp;
	
	s->Q1->size++;


}
/*
 * This funciton pops a value off of the stack. It does this by moving all 
values
 * that are currently on the stack to the other queue. The stack top is 
maintained
 * at the back of the queue list. 
 */
void linkedListStackPop(struct linkedListStack *s) {
	
        // FIXME: you must write this
        assert(!linkedListStackIsEmpty(s));

	while((s->Q1->size) > 1)
	{
		listQueueAddBack(s->Q2, s->Q1->firstLink->next->value);
		listQueueRemoveFront(s->Q1);
	}		

	listQueueRemoveFront(s->Q1);

	struct listQueue* temp = s->Q2;
	s->Q2 = s->Q1;
	s->Q1 = temp;
	
}
/*
 * This function returns the value that is at the back of the queue that 
is 
 * maintaing the values of the stack. 
 */
TYPE linkedListStackTop(struct linkedListStack *s) {

       // FIXME: you must write this
       return s->Q1->lastLink->value;

}

/*
 * This function gores through the stack and removes each link in the 
queue.
 * It then frees the struct itself. 
 */
void linkedListStackFree(struct linkedListStack *s){
	
      assert(s != 0);
	
	while (s->structSize != 0) 
	{
		linkedListStackPop(s);
	}

	free(s->Q1->firstLink);
	free(s->Q2->firstLink);
	free(s->Q1);
	free(s->Q2);

	free(s);



}

/*
 * Main is used to test the stack ADT.
 */
int main(int argc, char* argv[])
{
	struct linkedListStack *stack = linkedListStackCreate();

	//Test Stack
	//Push 4 values onto the stack
	printf("Pushing the value: 1\n");
	linkedListStackPush(stack, 1);
	printf("Pushed.\n\n");

	printf("Pushing the value: 2\n");
	linkedListStackPush(stack, 2);
	printf("Pushed.\n\n");

	printf("Pushing the value: 3\n");
	linkedListStackPush(stack, 3);
	printf("Pushed.\n\n");

	printf("Pushing the value: 4\n");
	linkedListStackPush(stack, 4);
	printf("Pushed.\n\n");



	//Print value at the top and then remove it
	printf("Value at the top of stack %d now being popped. \n",linkedListStackTop(stack));
	linkedListStackPop(stack);
	printf("Value popped.\n\n");

	printf("Value at the top of stack: %d now being popped. \n", linkedListStackTop(stack));
	linkedListStackPop(stack);
	printf("Value popped.\n\n");

	printf("Value at the top of stack: %d now being popped. \n", linkedListStackTop(stack));
	linkedListStackPop(stack);
	printf("Value popped.\n\n");

	printf("Value at the top of stack: %d now being popped. \n", linkedListStackTop(stack));  
	linkedListStackPop(stack);
	printf("Value popped.\n\n");

	//Try to pop when the stack is empty prints error:
	printf("Trying to pop empty stack:\n");

	linkedListStackPop(stack);

	
	//Push and Pop alternating
	printf("Pushing the value: 10\n");
	linkedListStackPush(stack, 10);
	printf("Pushed.\n\n");

	printf("Pushing the value: 11\n");
	linkedListStackPush(stack, 11);
	printf("Pushed.\n\n");

	printf("One more pop:\n");
	linkedListStackPop(stack);
	printf("Value at the top of stack: %d\n", 
linkedListStackTop(stack));

	linkedListStackFree(stack);

	return 0;

}


