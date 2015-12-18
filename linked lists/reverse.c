/*two methods of reversing linkedlists - iterative and recursive
iterative : O(n) time complexity, O(1) space complexity
recursive : O(n) time complexity, O(n) space complexity */
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

Node * iterative_reverse(Node *head){
	Node *current = head, *prev  = NULL,*temp;
	while(current != NULL){
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	return temp; //to be used as head
}	

Node * recursive_reverse(Node *head){
	if(head == NULL)
		return NULL;
	else if(head->next == NULL)
		return head; //pass the last node as the head pointer back to the first node to be returned as the new head
	else {
		Node *temp = head->next;
		head->next = NULL;
		Node *newHead = recursive_reverse(head->next);
		temp->next = head;
		return newHead;  //the last node is propagated back to the first node to be returned as the new head.
	}
}