//based on inclusion exclusion principle
//we have to find all the possible substring of a given string say the string is abc so it's substring will be (a,b,c,(a,b),(a,c),(b,c))

#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

void ans(string s, string output, int l, vector<string>&res){
    if(l>=s.length()){
        if(output.size()>0){
            res.push_back(output);
        }
        return;
    }

    //exclusion
    ans(s, output, l+1, res);

    //inclusion
    output.push_back(s[l]);
    ans(s, output, l+1, res);
}
int main(){
    string s;
    vector<string>temp;
    cout<<"Enter A String"<<endl;
    getline(cin,s);
    string output="";
    vector<string>res;
    int l=0;
    ans(s,output,l,res);

    for(auto i:res){
        cout<<i<<" ";
    }
}