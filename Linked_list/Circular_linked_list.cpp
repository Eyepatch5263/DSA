#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertANode(Node* &tail,int data){
    if(tail==NULL){
        Node* newNode=new Node(data);
        tail=newNode;
        tail->next=newNode;
    }
    else {
    Node* temp=tail;
    Node* newNode=new Node(data);
    newNode->next=tail->next;
    tail->next=newNode;
    tail=newNode;
    }
}


void printList(Node* tail){
    Node* temp=tail;
    tail=tail->next;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while(tail!=temp);
    cout<<tail->data;
    cout<<endl;
}

int getLength(Node* &temp, Node* &tail){
    int count=1;
    while(temp!=tail){
        count++;
        temp=temp->next;
    }
    return count;
}

void deleteFromBeg(Node* &tail){
    Node* temp=tail->next;
    tail->next=temp->next;
    temp->next=NULL;
    free(temp);
}

void deleteFromEnd(Node* &tail){
    Node* temp=tail->next;
    Node* temp2=tail;
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=tail->next;
    tail->next=NULL;
    free(tail);
    tail=temp;
}

void deleteFromPos(Node* &tail,Node*temp,int pos){
    if(pos==1){
        deleteFromBeg(tail);
        return;
    }
    if(pos==getLength(temp,tail)){
        deleteFromEnd(tail);
        return;
    }
    else{
        Node* temp1=tail->next;
        Node* temp2=temp1;
        for(int i=1;i<pos-1;i++){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp2=temp2->next;
        temp1->next=temp2->next;
        temp2->next=NULL;
        free(temp2);
        return;
    }
}

// void isCircular(Node*temp, Node*tail){
//     int length=getLength(temp,tail);
//     for(int i=1;i<length;i++){
//         temp=temp->next;
//     }
//     if(temp->next==tail){
//         cout<<"Linked list is circular"<<endl;
//     }
//     else{
//         cout<<"Linked list is not circular"<<endl;
//     }
// }


//using floyds algo
bool isCircular(Node* head){
    if(head==nullptr)
    return true;
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast && slow==head){
            return true;
        }
        if(slow==fast && slow!=head)
        return false;
    }
    return false;
}

void isLoopPresent(Node* temp, Node* tail){
    map<Node*,bool>visited;
    tail->next=temp->next;
    while(temp!=NULL){
        if(visited[temp]==true){
            cout<<temp->data<<endl;
            cout<<"Loop present"<<endl;
            break;
        }
        visited[temp]=true;
        temp=temp->next;
    }
}

//floyds algo for fast and slow pointer
//detecting the loop by checking if slow and fast pointer meets anywhere
Node* isLoop(Node* temp){
    Node* slow=temp;
    Node* fast=temp;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

//finding the starting node of the loop
// in this we maintain two pointers one where the slow and fast pointers have met and one at the head of the linked list and then we move both the pointers until the meet and return the node where they meet that would be the first element of the loop
Node* getStartingNodeOfLoop(Node* temp){
    if(temp==NULL)
    return NULL;
    Node* intersection=isLoop(temp);
    Node* slow=temp;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

//remove the loop by setting up two pointers where the first element have been found and we iterate with the second pointer
Node* removeLoop(Node* temp){
    if(temp==NULL){
        return NULL;
    }
    Node* start=getStartingNodeOfLoop(temp);
    Node* slow=start;
    while(slow->next!=start){
        slow=slow->next;
    }
    slow->next=NULL;
    return temp;
}





int main(){
    Node* tail=NULL;
    insertANode(tail,10);
    Node* temp=tail;

    insertANode(tail,20);
    printList(tail);

    insertANode(tail,30);
    printList(tail);

    insertANode(tail,40);
    printList(tail);

    insertANode(tail,50);
    printList(tail);
    if(isLoop(temp)!=NULL){
        cout<<"Loop is present"<<endl;
    }
    else{
        cout<<"Loop is not present"<<endl;
    }
    Node* ans=getStartingNodeOfLoop(temp);
    cout<<ans->data;
    // isCircular(temp,tail);
    // deleteFromBeg(tail);
    // printList(tail);
    // deleteFromEnd(tail);
    // deleteFromPos(tail,temp,4);
    // printList(tail);

}