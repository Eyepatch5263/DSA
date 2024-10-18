#include<iostream>
#include<algorithm>
using namespace std;
void bubbleSort(int arr[], int n){
    if(n==1 || n==0 ) return;
    int i;
    for(i=0;i<n-1;i++){
        if(arr[i] < arr[i+1])
        swap(arr[i], arr[i+1]);
    }
    
    return bubbleSort(arr,n-1);

}

int main(){
    int arr[]={2,3,65,43,21,7,90};
    int i=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    cout<<"The sorted array is: ";
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    
}