/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if(head==NULL) return -1;
	if (head->next == NULL)return head->num;
	struct node *temp = head;
	int count = 0,even_len=0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (count % 2 == 0) even_len = 1;
	count=count/2;
	while (count > 1)
	{
		head = head->next;
		count--;
	}
	if (even_len==1)		return ((head->num) + (head->next->num)) / 2;
	return head->next->num;
}
