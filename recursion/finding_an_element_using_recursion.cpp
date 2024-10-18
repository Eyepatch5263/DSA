#include<iostream>
bool Found(int arr[],int size,int target){
    if(size==0) return false;
    else if(arr[0]==target) return true;
    return  Found(arr+1,size-1,target);
}
using namespace std;
int main(){
    int array[]={1,2,3,4,5,6,7};
    int size=sizeof(array)/sizeof(array[0]);
    int target;
    cout<<"Target"<<endl;
    cin>>target;
    int ans=Found(array,size,target);
    if(ans){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
}