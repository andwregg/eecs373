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

	list_t* current_element;

	current_element = *head;
	while(current_element->next != NULL && current_element->next->index < new_element->index){
		current_element = current_element->next;
	}
	new_element->next = current_element->next;
	current_element->next = new_element;

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

	list_t* previous_list;
	list_t* current_list;
	list_t* next_list;

	previous_list = NULL;
	current_list = *head;
	while(current_list != NULL){
		next_list = current_list->next;
		current_list->next = previous_list;
		previous_list = current_list;
		current_list = next_list;
	}

	return head;
}

