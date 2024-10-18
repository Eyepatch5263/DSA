#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

int getLength(Node* &head){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void insertAtBeg(Node* &head, int data){
    Node* newNode=new Node(data);
    newNode->next=head;
    head=newNode;
}

void insertAtEnd(Node* &tail,int data){
    Node* newNode=new Node(data);
    if(tail==NULL){
        tail=newNode;
    }
    tail->next=newNode;
    tail=newNode;
}

void insertAtPos(Node* &head, Node* &tail, int data, int pos){
    //insert at beg
    if(pos==1){
        insertAtBeg(head,data);
        return ;
    }
    Node* temp=head;
    //insert at pos
    if(pos>1){
        for(int i=1;i<pos-1;i++){
            if(temp==NULL){
                cout<<"Invalid position"<<endl;
                return;
            }
            temp=temp->next;
        }
        Node* newNode=new Node(data);
        newNode->next=temp->next;
        temp->next=newNode;
    }

    //insert at end
    if(getLength(head)==pos){
        insertAtEnd(tail,data);
        return;
    }
}


void PrintNode(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deleteFromStart(Node* &head){
    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    free(temp);
}

void deleteFromEnd(Node* &head, Node* &tail){
    Node* temp=head;
    int length=getLength(head);
    for(int i=1;i<length-1;i++){
        temp=temp->next;
    }
    free(tail);
    tail=temp;
    temp->next=NULL;
}

void deleteAtPos(Node* &head, Node* &tail, int pos){
    if(pos==1){
        deleteFromStart(head);
        return;
    }
    else if(pos==getLength(head)){
        deleteFromEnd(head,tail);
        return;
    }
    Node *prev=head;
    Node *curr=head;
    for(int i=1;i<pos-1;i++){
        prev=prev->next;
        curr=curr->next;
    }
    curr=curr->next;
    prev->next=curr->next;
    curr->next=NULL;
    free(curr);
}


int main(){
    Node *node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    PrintNode(head);
    insertAtEnd(tail,20);
    PrintNode(head);
    insertAtEnd(tail,30);
    PrintNode(head);
    insertAtPos(head,tail,80,4);
    PrintNode(head);
    // deleteFromStart(head);
    // PrintNode(head);
    // deleteFromEnd(head,tail);
    // PrintNode(head);
    deleteAtPos(head,tail,4);
    PrintNode(head);
    cout<<"head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data<<endl;
    return 0;
}