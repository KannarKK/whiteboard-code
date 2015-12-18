/*two methods of finding intersection of linkedlists : 
intersection using length : O(max(len1,len2)) time complexity, O(1) space complexity
intersection using stack : O(max(len1,len2)) time complexity, O(len1+len2) space complexity */
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

Node * intersection_using_length (Node * head1, Node *head 2){
	Node *p1 = head1, *p2 = head2;
	int len1=0, len2=0, diff;
	while(p1!=NULL){
		len1++;
		p1=p1->next;
	}
	while(p2!=NULL){
		len2++;
		p2=p2->next;
	}
	if(len1 > len2){	//we need to move ptr in LL 1
		ptrdiff = len1-len2;
		p1 = head1;
		p2 = head2;
		while(ptrdiff--){
			p1 = p1->next;
		}
	}
	else {	//we need to move ptr in LL2
		ptrdiff = len2-len1;
		p1 = head1;
		p2 = head2;
		while(ptrdiff--){
			p2 = p2->next;
		}
	}
	//move both pointers now simultaneously
	while(p1!=p2){
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1; //as the intersection node;
}

struct stack{
	Node * p;
};
typedef struct stack Stack; //all stack operations are assumed to return ptr to nodes of type Node 
/*operations on stack:
 > push() O(1)
 > pop() O(1)
 */

Node * intersection_using_stack (Node * head1, Node * head2){
	Node *p1 = head1, *p2 = head2;
	int len1=0, len2=0, diff;
	while(p1!=NULL){
		len1++;
		p1 = p1->next;
	}
	while(p2!=NULL){
		len2++;
		p2 = p2->next;
	}
	Stack S1[len1], S2[len2];
	p1 = head1, p2 = head2;
	while(p1!=NULL){
		S1.push(p1);
		p1 = p1->next;
	}
	while(p2!=NULL){
		S2.push(p2);
		p2 = p2->next;
	}
	p1 = S1.top(), p2 = S2.top(); //initialize to top node in both stacks 
	Node * same_node; 
	while(p1==p2){
		same_node = p1;
		p1 = S1.pop();
		p2 = S2.pop();
	}
	return same_node; //as the intersection node;
}

