#include <iostream>
#include <stack>
using namespace std;

class Stack{
    public:
    int size;
    int* arr;
    int top;

    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }
    int peek(){
        if(top>=0 && top<size){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    void isEmpty(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"Stack is not empty"<<endl;
        }
    }
};
int main(){
    Stack st(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(0);
    st.push(78);
    
    // cout<<st.peek()<<endl;
    // st.push(9);
    // cout<<st.peek()<<endl;
    // st.pop();
    // cout<<st.peek()<<endl;
    // st.pop();
    // cout<<st.peek()<<endl;
    // st.pop();
    // st.isEmpty();
}