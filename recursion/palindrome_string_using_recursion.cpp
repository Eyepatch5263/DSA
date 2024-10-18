#include<iostream>
#include<string.h>
using namespace std;
bool reverse(string& s,int i){
    if(i>=(s.size()/2))
	return 0;
	if(s[i]!=s[s.size()-1-i])
	return 0;
    else{
        return 1;
    }

	reverse(s,i++);
    
}
int main(){
    string s;
    cout<<"Enter a string"<<endl;
    cin>>s;
    int i=0;
    bool ans=reverse(s,i);
    if(ans){
        cout<<"Palindrome String";
    }
    else{
        cout<<"Not a Palindrome String";
    }
    

}