#include <iostream>
#include<stack>
using namespace std;

int main(){
    string s="hello";
    string ans="";
    stack<char>st;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }

    while(!st.empty()){
        char ch=st.top();
        ans.push_back(ch);
        st.pop();
    }

    cout<<"Reversed string is :"<<ans;
}