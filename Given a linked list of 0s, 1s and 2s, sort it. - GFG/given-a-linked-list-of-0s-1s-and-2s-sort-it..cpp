//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    
    Node* segregate(Node *head) {
        
         Node *zero= new Node(-0);
         Node *curr0=zero;
          Node *one= new Node(-1);
         Node *curr1=one;
          Node *two= new Node(-2);
         Node *curr2=two;
         Node *curr=head;
         
         while(curr!=NULL){
             if(curr->data==0){
                 curr0->next=new Node(0);
                 curr0=curr0->next;
             }
             else if(curr->data==1){
                 curr1->next= new Node(1);
                 curr1=curr1->next;
             }
             else{
                 curr2->next=new Node(2);
                 curr2=curr2->next;
             }
             
             curr=curr->next;
         }
          curr2->next=NULL;
         curr1->next=two->next;
         curr0->next=one->next;
         return zero->next;
        
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends