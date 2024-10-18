#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    string s;
    cout<<"Enter a sentence: ";
    getline(cin,s);
    int n=s.length();
    int i;
    for(i=n-1;i>=0;i--){
        if(s[i]!=' '){
            v.push_back(i);
            break;
        }
        else{
            continue;
        }
    }

    for(int j=i;j>=0;j--){
        if(s[j]==' '){
            v.push_back(j);
            break;
        }
        else{
            continue;
        }
    }

int ans;
    if(v.size()==1)
    ans=v[0]+1;
    else{
        ans=v[0]-v[1];
    }
    cout<<"Length of last word is: "<<ans;

    
}