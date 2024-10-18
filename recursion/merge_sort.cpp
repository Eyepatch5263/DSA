#include<iostream>
using namespace std;

void merge(int *arr,int l,int e){
    
    int mid=(l+e)/2;
    int len1=mid-l+1;
    int len2=e-mid;
    int* arr1= new int [len1];
    int* arr2= new int [len2];

    //copying values to both the newly made arrays
    int mainArrayIndex=l;
    for(int i=0; i<len1;i++){
        arr1[i]=arr[mainArrayIndex++];
    }

    mainArrayIndex=mid+1;
    for(int i=0;i<len2;i++){
        arr2[i]=arr[mainArrayIndex++];
    }


    int index1=0;
    int index2=0;
    mainArrayIndex=l;
    while(index1<len1 && index2 <len2) {
        if(arr1[index1]<arr2[index2])
            arr[mainArrayIndex++]=arr1[index1++];
        else{
            arr[mainArrayIndex++]=arr2[index2++];
        }
    }
    //if elements are remaining in first array then add them at end of array
    while (index1 < len1){
        arr[mainArrayIndex++]=arr1[index1++];
    }

    while(index2<len2){
        arr[mainArrayIndex++]=arr2[index2++];
    }

//for deleting heap memory that we allocated it previously
    delete []arr1;
    delete []arr2;
    
}


void mergeSort(int arr[],int l,int e){
    if (l>=e) return ;
    

    int mid=(l+e)/2;

    //sorting left part
    mergeSort(arr,l,mid);

    //sorting right part;
    mergeSort(arr,mid+1,e);

    //merging the two parts.
    merge(arr,l,e);
}


int main(){
    int arr[]={2,6,2,3,4,6,9,76,54,32,12,21};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}