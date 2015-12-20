/*
method 1: brute force approach involving counting, tracking and then split.
method 2: one-traversal split (tortoise-hare)
Both are O(n) time complexity and O(1) space complexity, but method 2 outperforms method 1 with just one traversal
*/
struct node{
    int data;
    struct node *next;
};
typedef struct node Node;

void splitByCountMethod(Node *head, Node **head1, Node **head2){
    int i, count=1;
    Node *ptr = head, Node *end;
    while(ptr->next!=head){
        count++;
        ptr = ptr->next;
    }   
    end = ptr;
    if(count ==1){  //single node LL
        *head1 = head;
        *head2 = NULL; //don't split
        return;
    }
    i =1;
    int j= count%2? count/2+1 : count/2;
    ptr = head;
    while (i < j){
        i++;
        ptr = ptr->next;
    }
    end->next = ptr->next;
    ptr->next = head;
    *head1 = head;
    *head2 = end->next;
}

void split_one_traversal(Node *head, Node **head1, Node **head2){
    Node *p  =head, *q = head;
    head2 = NULL;
    while(q->next!=head && q->next->next!=head){
        p = p->next;
        q = q->next->next;
    }
    if(q->next->next == head)  //odd
            q = q->next;
    *head1 = head;
    if(head->next!=head)  //single node LL
        *head2 = p->next; 
    q->next = p->next;
    p->next = head;
}

/*Test cases:
1  should return head1=1, head2 = NULL
1->2->1 should split to 1 and 2
1->2->3->1 should split to 1->2->1 and 3
1->2->3->4->1 should split to 1->2->1 and 3->4->3
*/