#include <stdio.h>
#include "double_linked_list.h"

// Points to the input and prints the rest of the linked list data until
//	it reaches NULL, the linked list is traversed via next, making it
//	"print forwards".
void print_forward(DoubleLinkedList *node) {
	DoubleLinkedList *temp;
	for(temp = node; temp != NULL; temp = temp->next) {
		printf("%d ", temp->value);
	}
	printf("\n");
}

// Points to the input and prints the rest of the linked list data until
//	it reaches NULL, the linked list is traversed via prev, making it
//	"print backards".
void print_backward(DoubleLinkedList *node) {
	DoubleLinkedList *temp;
	for(temp = node; temp != NULL; temp = temp->prev) {
		printf("%d ", temp->value);
	}
	printf("\n");
}

// Adds new_node after base_node, if base_node->next points to null (meaning
//	that base_node is at the end of the linked list) then 
//	base_node->next->prev is skipped so that we don't trigger a segmentation
//	fault (because we cannot dereference NULL).  
void add_node(DoubleLinkedList *base_node, DoubleLinkedList *new_node) {
	new_node->next = base_node->next;
	new_node->prev = base_node;
	if (base_node->next != NULL) {
		base_node->next->prev = new_node;
	}
	base_node->next = new_node;
}

// Adds new_head before old_head old_head->next does not change because
//	we are adding to the very beginning of the linked list.
void add_at_head(DoubleLinkedList *old_head, DoubleLinkedList *new_head) {
	new_head->prev = NULL;
	new_head->next = old_head;
	old_head->prev = new_head;
}

// Will remove the node after base_node if base_node is not at the end of
//	the linked list (again, we cannot dereference NULL).
void rm_node(DoubleLinkedList *base_node) {
	if (base_node->next != NULL) {
		base_node->next->next->prev = base_node;
		base_node->next = base_node->next->next;
	}
}

// Removes base_node from the rest of the linked list, if it is byitself
//	(meaning prev and next are NULL) it just sets next to NULL.
void rm_at_head(DoubleLinkedList *base_node) {
	if (base_node->next != NULL) {
		base_node->next->prev = NULL;
	}
	base_node->next = NULL;
}

float linked_mean(DoubleLinkedList *root_node) {
}

float linked_variance(DoubleLinkedList *root_node) {
}

int linked_size(DoubleLinkedList *root_node) {
}

int linked_min(DoubleLinkedList *root_node) {
}
