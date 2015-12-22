/*N people. Every Mth person is removed, until one only remains. 
Time complexity: O(NM)
Space complexity: O(1) */

int josephus(Node *head, int M){
    head = make_circular(head); //make linkedlist circular if not. O(n) //preprocessing
    int N = count(head); // number of people. O(n)  //preprocessing
    Node *temp = NULL;
    for(int i=1; i<N;i++){   //N-1 rounds
        for(int j=1; j<M; j++)  //M-1 skips to remove Mth element
            p = p->next;
        temp = p->next; //Mth element
        p->next = p->next->next;
        free(temp);
        temp = NULL;
    }
    return p->data; //last man standing
}
