#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
	// FIXME: you must write this
	
	//Allocate memory for front and back Sentinels
	list->frontSentinel = malloc(sizeof(struct Link));
	list->backSentinel = malloc(sizeof(struct Link));

	//Point front and back sentinels to each other
	list->frontSentinel->next = list->backSentinel;
	list->backSentinel->prev = list->frontSentinel;

	//point front's prev pointer to NULL, and back's next ptr to NULL
	list->frontSentinel->prev = NULL;
	list->backSentinel->next = NULL;
	
	//Initialize list size to 0
	list->size = 0;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this

	//Allocate memory for new link and init with value passed in
	struct Link* temp = malloc(sizeof(struct Link));
	temp->value = value;

	//Update the link's prev and next pointers
	link->prev->next = temp;
	temp->prev = link->prev;
	link->prev = temp;
	temp->next = link;

	//Update list size
	list->size++;

	
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXME: you must write this

	//updates pointers to links surrounding the target link
	link->prev->next = link->next;
	link->next->prev = link->prev;

	//Decrement list size
	list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	
	//Call addLinkBefore and pass in frontSentinel->next
	addLinkBefore(list, list->frontSentinel->next, value);

}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	
	//Call addLinkBefore and pass in backSentinel
	addLinkBefore(list, list->backSentinel, value);

}


/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
	// FIXME: you must write this

	//returns the value directly after frontSentinel
	return list->frontSentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
	// FIXME: you must write this

	//Returns value directly before backSentinel
	return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this

	//if list is empty, print message to user
	if(linkedListIsEmpty(list))
	{
		printf("List is empty");
	}
	else
	{
		//Create temp pointer to point to target link for removal
		struct Link* temp = list->frontSentinel->next;

		//Update link pointers
		list->frontSentinel->next = temp->next;
		temp->next->prev = list->frontSentinel;

		//Decrement list size
		list->size--;

		//free memory allocated for the target link
		free(temp);
	}
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this
	
	//Print message to user if list is empty
	if(linkedListIsEmpty(list))
	{
		printf("List is empty");
	}
	else
	{

		//Create temp pointer to target link
		struct Link* temp = list->backSentinel->prev;

		//Update link pointers
		list->backSentinel->prev = temp->prev;
		temp->prev->next = list->backSentinel;
		
		//Derement list size
		list->size--;

		//free memory allocated for target link
		free(temp);
	}
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this
	
	//If front and back sentinels point to each other, the list is empty
	if(list->frontSentinel->next == list->backSentinel)
	{
		return 1;
	}
	return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	// FIXME: you must write this

	//Notify user if list is empty
	if(linkedListIsEmpty(list))
	{
		printf("List is empty");
	}
	else
	{
		//set temp pointer to help traverse the list
		struct Link* temp = list->frontSentinel->next;
		//loop variable to control when the while loop should end
		int loop = list->size;
		
		//Prints while list is not empty and loops to # of elements
		while(!linkedListIsEmpty(list) && loop > 0)
		{
			printf("Value is: %d\n", temp->value);
			temp = temp->next;
			loop--;
		}
	}
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	
	//Bag is unordered so I randomly selected to AddFront
	linkedListAddFront(list, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this

	//If list is empty, notify user
	if(linkedListIsEmpty(list))
	{
		printf("List is empty");
	}
	else
	{
		//Set up temp pointer to help traverse the list
		struct Link* temp = list->frontSentinel->next;

		//Loop variable controls when while loop ends
		int loop = list->size;

		while (!linkedListIsEmpty(list) && loop > 0)
		{
			//Return 1 if match is found
			if(temp->value == value)
			{
				return 1;
			}
			else
			{
				//If no match, traverse to  next link
				temp = temp->next;
				loop--;
			}
			
		}
	}
	return 0;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	
	//If value is not found in bag, notify user and exit
	if(!linkedListContains(list, value))
	{
		printf("Not found in list");
	}
	else
	{
		//set temp pointer to first link node
		struct Link* temp = list->frontSentinel->next;

		//loop variable controls while loop iterations
		int loop = list->size;

		//Since we only remove first occurrence. bool marks whether
		//we've already removed once and helps exit loop
		int bool = 0;
		
		while(!linkedListIsEmpty(list) && loop > 0 && bool == 0)
		{
			if(temp->value == value)
			{
				//Call removeLink to remove target link
				removeLink(list, temp);

				//free up temp
				free(temp);
	
				loop--;
				bool = 1;
			}
			else
			{
				//if value not found, traverse to next link
				temp = temp->next;
				loop--;
			}
		}
	}
			
}
