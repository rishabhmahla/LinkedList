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
}

// Driver code
int main(){

    
    Node *head = llinput();
    llprint(head);


}
