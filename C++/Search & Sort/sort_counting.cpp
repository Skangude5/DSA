//
//  counting_sort.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 08/12/20.
//

#include <iostream>
using namespace std;

void countingSort(int arr[], int max, int range){
    int countArray[range];
    int outputArray[max];
    for (int i=0; i<range; i++) {
        countArray[i]=0;
    }
    for (int i=0; i<max; i++) {
        ++countArray[arr[i]];
    }
    for (int i=1; i<range; i++) {
        countArray[i] = countArray[i] + countArray[i-1];
    }
    for (int i=0; i<max;i++) {
        outputArray[--countArray[arr[i]]] = arr[i];
    }
    for (int i=0; i<max; i++) {
        arr[i] = outputArray[i];
    }
}
int main(){
    int max=0,range=0;
          cout<<"Enter array size & Input range: ";cin>>max>>range;
    int a[max];
          cout<<"enter array element : ";
          for (int i=0; i<max; i++) {
              cin>>a[i];
          }
     countingSort(a, max, range);
       for (int i=0; i<max; i++) {
          cout<<a[i]<<",";
       }
       cout<<endl;
    return 0;
}
