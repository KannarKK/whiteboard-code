struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

int findCycle(Node *head){
	Node *p = head, *q = head;  // p = slow pointer, q= fast pointer
	//tortoise-hare algorithm i.e. Floyd Cycle detection algorithm
	while(q != NULL){
		q = q->next? (q->next->next?q->next->next:NULL):NULL;
		p = p->next; 
		if(q == p){
			break;
		}
	}
	if(p == q){ //presence of cycle. we need to find the start node
	    *p = head;
        while(p != q){
			p = p->next; //move at the same pace
			q = q->next;
		}
	    printf("Cycle found. Starts at %d", p->data);
	    return 1;
	}
	printf("No cycle. Linked List terminates.");
	return 0;
}
/* Explanation:

If the cycle starts after length 'x', and both the tortoise and hare meet at some distance 'y' after 'x',
then, the remaining distance within the loop be 'z'.
=> Tortoise moved 'x+y', and Hare moved 'x+y+z+y', to meet at some distance 'y' after 'x'.
Considering both took the same time to meet at some point, using speed formula,
 2(x+y) = x+2y+z => x=z. This implies, we can find the start point if we reset one pointer to beginning of LL 
 and the other to the original meeting point, and then move them at same pace (x=z). => This gives a new meeting
 point which is the start of cycle.
 */