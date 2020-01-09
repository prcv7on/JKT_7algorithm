

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;	
}LNode;

LNode* mergeTwoLists(LNode* l1, LNode* l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	LNode ln;
	LNode* tmp = &ln;
	LNode* l3 = &ln;
	l3->next = l1->val <= l2->val ? l1 : l2;
	
	while (l1 && l2) {
		if (l1->val <= l2->val) {
			tmp->next = l1;
			l1 = l1->next;
		}
		else {
			tmp->next = l2;
			l2 = l2->next;
		}
		tmp = tmp->next;
	}
	tmp->next = l1 == NULL ? l2 : l1;

	return l3->next;
}

void printLNode(LNode* h) {
	while (h != NULL) {
		printf("%d -> ", h->val);
		h = h->next;
	}
	printf("NULL\n");
}


int main()
{
	LNode a1, a2, a3;
	LNode b1, b2, b3,b4;
	a1.val = 1; a1.next = &a2;
	a2.val = 4; a2.next = &a3;
	a3.val = 5; a3.next = NULL;
	b1.val = 1; b1.next = &b2;
	b2.val = 2; b2.next = &b3;
	b3.val = 3; b3.next = &b4;
	b4.val = 6; b4.next = NULL;

	LNode* c1 = mergeTwoLists(&a1,&b1);
	printLNode(c1);

	printf("\n");
	system("pause");

}





