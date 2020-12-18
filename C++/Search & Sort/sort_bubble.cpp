//
//  bubble_sort.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 03/12/20.
//

#include <iostream>
using namespace std;

void bubbleSort(int a[], int min, int max){
    for (int i=min; i<max; i++) {
        for (int j = min; j<max-i-1; j++) {
            if (a[j]>a[j+1]) {
                a[j] = a[j] + a[j+1];
                a[j+1] = a[j] - a[j+1];
                a[j] = a[j] - a[j+1];
            }
        }
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
    bubbleSort(a, 0, max);
    for (int i=0; i<max; i++) {
       cout<<a[i]<<",";
    }
    cout<<endl;
    return 0;
}
