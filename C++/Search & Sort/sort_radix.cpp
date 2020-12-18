//
//  radix_sort.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 08/12/20.
//

#include <iostream>
using namespace std;

void countingSort(int arr[], int max,int div){
    int range = 10;
    int countArray[range];
    int outputArray[max];
    for (int i=0; i<range; i++) {
        countArray[i]=0;
    }
    for (int i=0; i<max; i++) {
        ++countArray[(arr[i]/div)%10];
    }
    for (int i=1; i<range; i++) {
        countArray[i] = countArray[i] + countArray[i-1];
    }
    for (int i=max-1; i>=0;i--) {
        outputArray[--countArray[(arr[i]/div)%10]] = arr[i];
    }
    for (int i=0; i<max; i++) {
        arr[i] = outputArray[i];
    }
}
int getMax(int arr[], int max);
void radixSort(int arr[], int max){
    int maximum = getMax(arr, max);
    for (int div=1;maximum/div>0;div*=10) {
        countingSort(arr, max,div);
    }
}
int getMax(int arr[], int max){
    int temp = arr[0];
    for (int i=1; i<max; i++) {
        if (temp<arr[i]) {
            temp = arr[i];
        }
    }
    return temp;
}
int main(){
    int max=0;
          cout<<"Enter array size :";cin>>max;
    int a[max];
          cout<<"enter array element : ";
          for (int i=0; i<max; i++) {
              cin>>a[i];
          }
     radixSort(a, max);
       for (int i=0; i<max; i++) {
          cout<<a[i]<<",";
       }
       cout<<endl;
    return 0;
}
