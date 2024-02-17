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
int lllength(Node *head){
    int len = 0;
    Node *temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

// Print ith node of LL;
void llPrintith(Node *head, int index,int length){
    if(index<0 || index>length){
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

//Update value at ith position

void llUpdateith(Node *head, int index,int value,int length){
    if(index<0 || index>length){
        cout<<"-1";
        return;
    }
    
    int start = 0;
    Node *temp = head;
    while(temp){
        if(start == index){
            temp->data=value;

            return;
        }
        start++;
        temp = temp->next;
    }
    cout<<"-1"<<endl;
}

// Insert value at ith position

void llInsertith(Node *head, int index,int value,int length){
    if(index<0 || index>length){
        cout<<"-1";
        return;
    }
    
    int start = 0;
    Node *temp = head;
    while(temp){
        if(start == index-1){
            Node *bkp = temp->next; //Holds the address of the next node
            Node *newnode = new Node(value); //Creates new node to be inserted
            temp->next = newnode; //connection between newnode and the previous node
            newnode->next = bkp; //connection between newnode and the next node

            return;
        }
        start++;
        temp = temp->next;
    }
    cout<<"-1"<<endl;
}

// Delete value at ith position

void llDelIth(Node *head, int index,int length){
    if(index<0 || index>length){
        cout<<"Error:Index out of range"<<endl;
        return;
    }
    
    int start = 0;
    Node *temp = head;
    while(temp){
        if(start == index-1){
            temp->next = temp->next->next;
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
    int length = lllength(head);
    llInsertith(head,3,8,length);
    llprint(head);
    llDelIth(head,3,length);
    llprint(head);
    


}
