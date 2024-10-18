#include<iostream>
int sum(int arr[],int size){
    if(size==0) return 0;
    else if(size==1) return arr[0];
    int rem=sum(arr+1,size-1);
    return  rem + arr[0];
}
using namespace std;
int main(){
    int array[]={1,2,3,4,5,6,7};
    int size=sizeof(array)/sizeof(array[0]);
    int ans=sum(array,size);
    cout<<"Sum of the elements in the array is : "<<ans<<endl;
}