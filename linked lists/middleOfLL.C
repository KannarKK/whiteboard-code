/*Two methods to find middle of linked lists depending on which node should be selected in case the number of nodes 
is even i.e. the middle of the linked list should be floor(n/2) or ceil(n/2).
middle_1() : O(n) time complexity O(1) space complexity
middle_2() : O(n) time complexity O(1) space complexity */

struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

//middle node in case of even is ceil(n/2)
Node * middle_1(Node *head){
	if(head==NULL) return NULL;
	if(head->next==NULL) return head;
	Node *p = head; //slow ptr
	Node *q = head; //fast ptr with 2x speed compared to slow ptr
	//here p and q start at the same place. 
	while(q!=NULL && q->next!=NULL){
		p = p->next;
		q = q->next->next;
	}
	return p;
}

//middle node in case of even is floor(n/2)
Node * middle_2(Node *head){
	if(head==NULL) return NULL;
	if(head->next==NULL) return head;
	Node *p = head;
	Node *q = head->next;
	//here q starts one node ahead of p (which gives floor, since it means q can quickly reach end, compared to middle_1())
	while(q!=NULL && q->next!=NULL){
		p = p->next;
		q = q->next->next;
	}
	return p;
}
/* Unit tests for middle_1():
1. LL: NULL   returns NULL
2. LL: 1->NULL  returns 1
3. LL: 1->2->NULL returns 2
4. LL: 1->2->3->NULL returns 2
5. LL: 1->2->3->4->NULL returns 3
6. LL: 1->2->3->4->5->6->NULL returns 4

Unit tests for middle_2():
1. LL: NULL   returns NULL
2. LL: 1->NULL  returns 1
3. LL: 1->2->NULL returns 1
4. LL: 1->2->3->NULL returns 2
5. LL: 1->2->3->4->NULL returns 2
6. LL: 1->2->3->4->5->6->NULL returns 3 */
