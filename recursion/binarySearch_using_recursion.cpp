#include<iostream>
using namespace std;
bool found(int arr[],int l,int e,int target){
    if(l > e) return false;
    int mid=l+(e-l)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(target>arr[mid]){
        return  found(arr,mid+1,e,target);
    }
    return found(arr,l,mid-1,target);
}
int main(){
    int arr[]={1,4,8,9,12,15,18};
    int size=sizeof(arr)/sizeof(arr[0]);
    int target;
    cout<<"Target"<<endl;
    cin>>target;
    int l=0,e=size-1;
    bool ans=found(arr,l,e,target);
    if(ans){
        cout<<"Found";
    }
    else{
        cout<<"Didn't find";
    }

}