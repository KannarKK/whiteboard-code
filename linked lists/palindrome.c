struct node{
    int data;
    struct node *next;
};
typedef struct node Node;

struct stack{
    Node * p;
};
typedef struct stack Stack; //all stack operations are assumed to return ptr to nodes of type Node 
/*operations on stack:
 > push() O(1)
 > pop() O(1)
 */

 int palindrome_stack(Node *head){
    Node * ptr = head;
    Stack S[MAX_LENGTH];
    while(ptr!=NULL){
        S.push(ptr->data);
        ptr = ptr->next;
    }
    ptr = head;
    while(ptr!=NULL){
        if(S.pop() != ptr->data) return 0;
        else ptr = ptr->next;
    }
 }

 Node *reverse(Node *head);  //see reverse.c file for implementation

 int palindrome_method2(Node *head){
    Node *p =head, *q =head,*prev=NULL,*temp_middle;
    int count = 0;
    while(q!=NULL && q->next!=NULL){
        prev = p;
        p = p->next; //slow ptr;
        q = q->next->next; // fast ptr; to traverse to middle of list
        if(q!=NULL) count+=2;
        else count+=1;
    }
    //in case it's odd, don't include p in reversal. (currently p is at the middle of list)
    if(count%2){
        prev = p;
        p = p->next;
    }
    prev->next = reverse(p);
    p = head;
    temp_middle = prev->next;
    while(p!=NULL && temp_middle!=NULL){
        //if(p == prev && count%2) return 1; not required since both pointers cannot be non-NULL in case of odd and p == prev
        if(p->data == temp_middle->data){
            p = p->next;
            temp_middle = temp_middle->next;
        }
        else return 0;
    }
    return 1;
    //IMP: I do not reconstruct the Linked List, which should be done.
 }

 