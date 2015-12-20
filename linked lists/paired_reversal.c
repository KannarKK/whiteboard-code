/*Concept:
1->2->3->4->NULL should become 2->1->4->3->NULL
If odd, 1->2->3->4->5->NULL should become 2->1->4->3->5->NULL 

At any given point of reversal of two nodes (a->b), we need to take care of 4 nodes.
....->x->a->b->y->....
First, b->a, then x->b and a->y.
....->x->b->a->y->....
If first node, skip x->b connection, since x is NULL and make b as head.
In code, a = prev, b = cur;

iterative_pair_reverse : O(n) time complexity, O(1) space complexity
recursive_pair_reverse : O(n) time complexity, O(n) space complexity
*/

struct node{
    int data;
    struct node *next;
};
typedef struct node Node;

Node * iterative_pair_reverse(Node *head){
    Node *cur=head, *prev =NULL, *x = NULL, *y=NULL;
    while(cur!=NULL && cur->next!=NULL){
        prev = cur;  //a
        cur = cur->next;  //b
        y = cur->next;
        cur->next = prev;  //reverse a->b
        prev->next = y;   //forge new connection a->y
        if(x==NULL) //first time
            head = cur;
        else
            x->next = cur;   //forge connection x->b
        x = prev;    //make b as the new x for the next pair
        cur = y;     //make y as the new cur of the next pair
    }
    return head;
}

Node * recursive_pair_reverse(Node *head){
    if(head==NULL || head->next == NULL)
        return head;
    else{
        Node *prev = head;  //a
        Node *cur = head->next; //b
        prev->next = cur->next;
        cur->next = prev;  //b->a
        head = cur;
        head->next->next = recursive_pair_reverse(head->next->next); // a->y or x->b same in case of recursion
        return head;
    }
}

