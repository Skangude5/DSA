
//
//  insertion_sort.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 03/12/20.
//

#include <iostream>
using namespace std;

void insertionSort(int a[],int min, int max){
    for (int i=min+1; i<max; i++) {
        int key = a[i];
        int j = i - 1;
        while (j>=min && key < a[j]) {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
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
    insertionSort(a, 1, max);
    for (int i=0; i<max; i++) {
       cout<<a[i]<<",";
    }
    cout<<endl;
    return 0;
}
