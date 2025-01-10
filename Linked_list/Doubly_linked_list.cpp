#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

void insertAtHead(Node* &head,int data){
    Node* newNode=new Node(data);
    head->prev=newNode;
    newNode->prev=NULL;
    newNode->next=head;
    head=newNode;
}

void insertAtTail(Node* &tail,int data){
    Node* newNode=new Node(data);
    tail->next=newNode;
    newNode->prev=tail;
    newNode->next=NULL;
    tail=newNode;
}

int getLength(Node* &head){
    int count=0;
    Node*temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void insertAtPos(Node* &head, Node* &tail, int pos,int data){
    Node* newNode=new Node(data);
    Node* temp=head;
    if(pos==1){
        insertAtHead(head,data);
        return;
    }
    else if(pos==getLength(head)+1){
        insertAtTail(tail,data);
        return;
    }
    else{
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next->prev=newNode;
        temp->next=newNode;
        return;
    }
}

void deleteFromBeg(Node* &head){
    Node* temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    free(temp);
}

void deleteFromEnd(Node* &tail){
    Node* temp=tail;
    tail=tail->prev;
    temp->prev=NULL;
    tail->next=NULL;
    free(temp);
}

void deleteAtPos(Node* &head, Node* &tail, int pos){
    Node* temp=head;
    if(pos==1){
        deleteFromBeg(head);
        return;
    }
    else if(pos==getLength(head)){
        deleteFromEnd(tail);
        return;
    }
    else{
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->prev=NULL;
        temp->next=NULL;
        free(temp);
    }
}


void printNode(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    printNode(head);
    insertAtHead(head,20);
    printNode(head);
    insertAtTail(tail,50);
    printNode(head);
    insertAtPos(head,tail,4,80);
    printNode(head);
    // deleteFromBeg(head);
    // printNode(head);
    // deleteFromEnd(tail);
    // printNode(head);
    deleteAtPos(head,tail,3);
    printNode(head);
    cout<<"head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data<<endl;
    return 0;
}