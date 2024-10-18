#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
void reverse(string& s,int i){
    if(i>=(s.size()/2))
	return;
	swap(s[i],s[s.size()-1-i]);
	i++;
	reverse(s,i);
    
}
int main(){
    string s;
    cout<<"Enter a string"<<endl;
    cin>>s;
    int i=0;
    reverse(s,i);
    cout<<s;

}