//This type of question particularly involves two types either if we've to find the subarray/substring from a given string or the least/max sum of subarray from an array with given value
//here we'll solve minimum size of subarray less or equal to given value

#include<iostream>
using namespace std;
int main(){
    int arr[]={7,2,5,10,8};
    int  n=sizeof(arr)/sizeof(arr[0]);
    int l=0,e=0;
    int sum=0;
    int k=18;
    int size=INT16_MAX;
    for(int e=0;e<n;e++){
        sum+=arr[e];
        while(sum>=k){
            size=min(size,e-l+1);
            sum-=arr[l];
            l++;
        }
    }
    cout<<"Minimum Size: "<<size;
}