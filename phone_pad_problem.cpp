#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
void ans(string number,string mapping[],string output,vector<string>&res,int l){
    if(l>=number.length()){
        res.push_back(output);
        return;
    }

    int digit=number[l]-'0';
    string value=mapping[digit];
    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        ans(number,mapping,output,res,l+1);
        output.pop_back();
    }
}
int main(){
    string number;
    cout<<"Enter a Number";
    getline(cin,number);
    string output="";
    vector<string>res;
    string mapping[10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int l=0;
    if(number.length()==0){
        cout<<"Invalid";
    }
    ans(number,mapping,output,res,l);

    for(auto i:res){
        cout<<i<<" ";
    }

}