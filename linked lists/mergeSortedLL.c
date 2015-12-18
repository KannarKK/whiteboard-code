/*two methods of merging two sorted linkedlists : iterative and recursive
iterative: O(max(m,n)) time complexity, O(m+n) space complexity
iterative in-memory: O(max(m,n)) time complexity, O(1) space complexity
recursive  : O(min(m,n)) time complexity, O(min(m,n)) space complexity  */
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

Node * create(Node * nodeToCopy){
	Node * newnode = (Node *)malloc(sizeof(newnode));
	newnode->next = NULL;
	newnode->data = nodeToCopy->data;
	return newnode;
}
//Sort in ascending order to create a new list of nodes.
Node * iterative_merge(Node *head1, Node *head2){
	Node *p1 = head1, *p2 = head2,  *p3 = NULL, *head3;
	while(p1!=NULL && p2!=NULL){
		if(p1->data > p2->data){ 
			if(p3==NULL){
				p3 = create(p2);
				head3 = p3;
			}
			else p3->next = create(p2);
			p2 = p2->next;
		}
		else{
			if(p3==NULL){
				p3 = create(p1);
				head3 = p3;
			}
			else p3->next = create(p1);
			p1 = p1->next;
		}
		if(p1!=null)
			while(p1!=null){
				p3->next = create(p1); //join LL3 to remaining portion of LL1
				p1 = p1->next;
			}
		else
			while(p2!=null){
				p3->next = create(p2);
				p2 = p2->next;
			}
	}
	return head3;
}

//in this we create only one dummy node and do not recreate new nodes. LL1 and LL2 are lost.
Node * iterative_merge_inmemory(Node *head1, Node *head2){
	Node *dummynode = NewNode();
	Node *head3 = dummynode;
	Node *p1 = head1, *p2 = head2,*p3 = head3;
	while (p1!=NULL && p2 !=NULL){
		if(p1->data < p2->data) {
			p3->next = p1;
			p1 = p1->next;
			p3 = p3->next;
		}
		else{
			p3->next = p2;
			p2 = p2->next;
			p3 = p3->next;
		}
	}
	if(p1!=NULL)
		p3->next = p1;
	else 
		p3->next = p2;
	head3 = head3->next;
	free(dummynode);
	return head3;
}
//without dummy node
Node * iterative_merge_inmemory_2(Node *head1, Node *head2){
	Node *dummynode = NewNode();
	Node *head3 = NULL;
	Node *p1 = head1, *p2 = head2,*p3 = head3;
	while (p1!=NULL && p2 !=NULL){
		if(p1->data < p2->data) {
			if(p3==NULL){
				p3 = p1;
				head3 = p3;
			}
			else{
				p3->next = p1;
				p3 = p3->next;	
			}
			p1 = p1->next;
		}
		else{
			if(p3==NULL){
				p3 = p2;
				head3 = p3;
			}
			else{
				p3->next = p2;
				p3 = p3->next;
			}
			p2 = p2->next;
		}
	}
	if(p1!=NULL)
		p3->next = p1;
	else 
		p3->next = p2;
	return head3;
}

/*
  Node *head3 = recursive_merge_inmemory(head1, head2);
  */
Node * recursive_merge(Node *head1, *head2){
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;
	Node *p3  = NULL;
	if(head1->data < head2->data){
		p3 = head1;
		p3->next = recursive_merge_inmemory(head1->next, head2);
	}
	else {
		p3 = head2;
		p3->next = recursive_merge_inmemory(head1, head2->next);
	}
	return p3;
}