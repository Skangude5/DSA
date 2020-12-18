//
//  quick_sort.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 06/12/20.
//

#include <iostream>
using namespace std;

int partitionArray(int arr[], int start, int end){
    int pivot = arr[end];
    int pivotIndex = start;
    for(int i=start;i<end;i++){
        if(pivot>arr[i]){
            swap(arr[i],arr[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(arr[end],arr[pivotIndex]);
    return pivotIndex;
}
void quickSort(int arr[], int start, int end){
    if (start<end) {
        int pivot = partitionArray(arr,start,end);
        quickSort(arr, start, (pivot-1));
        quickSort(arr, (pivot+1), end);
    }
}
int main(){
    int max=0;
          cout<<"Enter array size: ";cin>>max;
    int a[max];
          cout<<"enter array element : ";
          for (int i=0; i<max; i++) {
              cin>>a[i];
          }
       quickSort(a, 0, max-1);
       for (int i=0; i<max; i++) {
          cout<<a[i]<<",";
       }
       cout<<endl;
    return 0;
}
