#include <iostream>
#include "Node.cpp"
using namespace std;


// Takes input from the user for the linked list data;
// If user gives -1 as input it will be considered termination of the linked list;

Node* llinput(){
    int data;
    Node *head = NULL;
    Node *tail = NULL;
    cin>>data;
    

    while(data != -1){
        Node *n = new Node(data);
        if(head == NULL){
            head = n;
            tail = n;
        }
        else{
            tail->next= n;
            tail = n;
        }
        cin>>data;
    }
    return head;
}

// Prints the linked list
void llprint(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Length of linked list
void lllength(Node *head){
    int len = 0;
    Node *temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    cout<<"Length of LL is "<<len<<endl;
}

// Print ith node of LL;
void LLPrintith(Node *head, int index){
    if(index<0){
        cout<<"-1";
        return;
    }
    
    int start = 0;
    Node *temp = head;
    while(temp){
        if(start == index){
            cout<<"Value at index "<<index<<" is "<<temp->data<<endl;
            return;
        }
        start++;
        temp = temp->next;
    }
    cout<<"-1"<<endl;
}

// Driver code
int main(){

    
    Node *head = llinput();
    llprint(head);
    lllength(head);
    LLPrintith(head,9);


}
