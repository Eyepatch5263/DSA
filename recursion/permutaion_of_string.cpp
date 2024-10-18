#include<iostream>
#include<vector>
#include <algorithm> 

using namespace std;
int main(){
    // vector<string>v;
    // string output="";
    // string s;
    // cout<<"Enter a string"<<endl;
    // getline(cin,s);
    // int n=s.length();
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         swap(s[i],s[j]);
    //         v.push_back(s);
    //     }
    //     s=s;
    // }
    // for(auto i:v){
    //     cout<<i<<" ";
    // }

vector<string>::iterator it;
    vector<string>v1={"dferfb","abfweesfe","ab"};
    vector<string>v2={"eidbaooo"};
    
    for(int i=0;i<v1.size();i++){
        if(find(v2.begin(),v2.end(),v1[i])==v2.end()){
            cout<<"true"<<endl;
            break;
        }
    }
    
    // it = search(v1.begin(), v1.end(), v2.begin(), v2.end()); 
    // if(it!=v2.end())
    // cout<<"found";
    // else{
    //     cout<<"not found";
    // }

    

}