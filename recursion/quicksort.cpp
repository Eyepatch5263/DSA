#include<iostream>
using namespace std;

int partition(int arr[],int l,int e){
    int pivot=arr[l];
    int count=0;
    for(int i=l+1;i<=e;i++){
        if(pivot>arr[i])
        count++;
    }

    int pivotIndex=count+l;
    swap(arr[l],arr[pivotIndex]);

    int i=l,j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(pivot>arr[i]){
            i++;
        }
        while(pivot<arr[j]){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
        
    }

    return pivotIndex;
}
void quickSort(int arr[], int l,int e){
    if(l>=e) return ;

    int p=partition(arr,l,e);

    //sorting the left part
    quickSort(arr,l,p-1);
    
    //sorting the right part
    quickSort(arr,p+1,e);

}
int main(){
    int arr[]={3,7,1,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0 ,n-1);
    cout<<"The sorted array is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}