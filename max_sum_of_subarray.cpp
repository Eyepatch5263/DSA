#include<iostream>
using namespace std;
int main(){
    int arr[]={7,2,5,10,8}; 
    int n=sizeof(arr);
    int currSum=0;
    int maxSum=0;
    for(int i=0;i<n;i++){
    currSum+=arr[i];
    if(currSum>0){
        currSum=currSum;
    }
    if(maxSum>currSum){
        maxSum=currSum;
    }
    }
    cout<<maxSum;
}