#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	list_t* current_element;	//placeholder variable for the current element in the linked list that is being looked at

	current_element = *head;
	while(current_element->next != NULL && current_element->next->index < new_element->index){ //check that we have not reached the end of the list and that the next element is still smaller than the new element
		current_element = current_element->next;	//set the current element to the next element
	}
	new_element->next = current_element->next; //set the next of the new element to the next of the current element
	current_element->next = new_element;	//set the next of the current element to the new element (insert the new element)

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

	list_t* previous_list;	//placeholder variable for the element we just looked at
	list_t* current_list;	//placeholder variable for the element we are currently looking at
	list_t* next_list;		//placeholder variable for the next element we will look at

	previous_list = NULL;	//haven't looked at anything yet
	current_list = *head;	//starting at the first element
	while(current_list != NULL){
		next_list = current_list->next;	//the next element we're going to look at is the next of the current element
		current_list->next = previous_list;	//the next of the now moved element is the previous element
		previous_list = current_list;	//the current element is now the previous element
		current_list = next_list;	//the next element is now the current element
	}

	return head;
}

