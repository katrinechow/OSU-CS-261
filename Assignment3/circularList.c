#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
	list->sentinel = malloc(sizeof(struct Link));
	list->size = 0;

	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
	struct Link* temp = malloc(sizeof(struct Link));
	temp->value = value;
	temp->next = NULL;
	temp->prev = NULL;

	return temp;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this

	//Allocate memory for the new link and init with value passed in
	struct Link* temp = createLink(value);

	//Update the link's prev and next pointers
	temp->next = link->next;
	link->next->prev = temp;
	link->next = temp;
	temp->prev = link;
	
	//Update list size
	list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
	if(link->prev == link->next)
	{
		link->prev->next = list->sentinel;
		link->prev->prev = list->sentinel;
		
	list->size--;
	}
	else
	{
	
		//Updates pointers to links surrounding the target link
		link->prev->next = link->next;
		link->next->prev = link->prev;
	
		//Decrement list size
		list->size--;
	}

}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
	int loop = list->size;
	
	while(!circularListIsEmpty(list) && loop > 0)
	{
		struct Link* temp = list->sentinel->next;
		removeLink(list, temp);
		loop--;
		free(temp);
	}

	free(list->sentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	
	//Call addLinkAfter and pass in sentinel
	addLinkAfter(list, list->sentinel, value);
}


/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this

	//Call addLinkAfter and pass in sentinel->prev
	addLinkAfter(list, list->sentinel->prev, value);

}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{

	// FIXME: you must write this

	assert(!circularListIsEmpty(list));

	 return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(!circularListIsEmpty(list));

	return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this

	if(circularListIsEmpty(list))
	{
		printf("List is empty");
	}
	else
	{
		//Create temp pointer to point to target link for removal
		struct Link* temp = list->sentinel->next;

		//Update link pointers
		list->sentinel->next = temp->next;
		temp->next->prev = list->sentinel;

		//Decrement list size
		list->size--;

		//Free memory allocated for target link
		free(temp);
	}
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	if(circularListIsEmpty(list))
	{
		printf("List is empty");
	}
	else
	{
		//Create temp pointer to target link for removal
		struct Link* temp = list->sentinel->prev;

		//Update link pointers
		list->sentinel->prev = temp->prev;
		temp->prev->next = list->sentinel;
	
		//Decrement list size
		list->size--;

		//free memory allocated for target link
		free(temp);
	}
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
	if(list->sentinel->next == list->sentinel->prev)
	{
		return 1;
	}
	return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
	
	//set temp pointer to help traverse the list
	struct Link* temp = list->sentinel->next;
	//loop variable to control when while loop ends
	int loop = list->size;

	//Prints while there are elements in list
	while(loop > 0)
	{
		printf("Value is: %f\n", temp->value);
		temp = temp->next;
		loop--;
	}

}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this

	//Notify user if list is empty
	if(circularListIsEmpty(list))
	{
		printf("List is empty");
	}
	else
	{
		int loop = list->size;

		struct Link* frontTemp = list->sentinel;
		struct Link* backTemp = list->sentinel;

		while(loop > 0)
		{	
			frontTemp->next = backTemp->prev;
			backTemp->prev = frontTemp->next;

			frontTemp = frontTemp->next;
			backTemp = backTemp->prev;

			loop--;
		}
	}
}
