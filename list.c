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
	

	if (new_element->index < head->index) {
		new_element->next = head;
		return new_element;
	}
	else {
		list_t* prev = NULL;
		list_t* iter = head;
		while(iter) {
			if (new_element->index < iter->index) {
				prev->next = new_element;
				new_element->next = iter;
				return head;
			}
			prev = iter;
			iter = iter->next;
		}
		prev->next = new_element;
	}
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

	list_t* next = NULL;
	list_t* curr = head;
	list_t* prev = NULL;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

