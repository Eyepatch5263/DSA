#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[4][4]={{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};
    int n=sizeof(arr[0]);
    vector<string>ans;
    vector<vector<int>>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i].push_back(0);
        }
    }
    cout<<n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<temp[i][j];
        }
    }

    

}