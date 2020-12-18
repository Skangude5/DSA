//
//  merge_sort.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 05/12/20.
//

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int i = left;int j = mid+1;int k = left;int temp[right];
    while (i<=mid && j<right) {
        if (arr[j]>=arr[i]) {
            temp[k] = arr[i];
            k++;i++;
        } else {
            temp[k] = arr[j];
            k++;j++;
        }
    }
    while(i<=mid){
        temp[k] = arr[i];
        k++;i++;
    }
    while (j<right) {
        temp[k] = arr[j];
        k++;j++;
    }
    for (int i = left; i<right; i++) {
        arr[i] = temp[i];
    }
}
void mergeSort(int arr[], int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr,left,mid,right);
    }
}
int main(){
        int max;
       cout<<"Enter array size: ";cin>>max;
       int a[max];
       cout<<"enter array element : ";
       for (int i=0; i<max; i++) {
           cin>>a[i];
       }
    mergeSort(a, 0, max);
    for (int i=0; i<max; i++) {
       cout<<a[i]<<",";
    }
    cout<<endl;
    return 0;
}
