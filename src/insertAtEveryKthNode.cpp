/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}
struct node * insertAtEveryKthNode(struct node *head, int K) {
	struct node * temp = head,*inserting_node;
	
	int count = 0, i = 1, pos = 0;
	if(head==NULL || K<=0)
		return NULL;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (K > count) return head;
	temp = head;
	while (temp != NULL)
	{ 
		pos++;
		if (pos > count) break;
		if (pos == K*i)
		{
			inserting_node = createNode(K);
			inserting_node->next = temp->next;
			temp->next = inserting_node;
			//if (pos == count) break;
			temp = temp->next->next;
			i++;
		}
		else
		{
			temp = temp->next;
		}
	}
	
	return head;
}
