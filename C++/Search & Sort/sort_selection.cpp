//
//  selection_sort.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 03/12/20.
//

#include <iostream>
using namespace std;

void selectionSort(int a[], int min, int max){
    for (int i = min; i<max-1; i++) {
        int minimum = a[i];
        for (int j = i+1; j<max; j++) {
            if (a[j]<minimum) {
                minimum = a[j]+minimum;
                a[j] = minimum - a[j];
                minimum = minimum - a[j];
            }
        }
        if (minimum!=a[i]) {
            a[i] = minimum + a[i];
            minimum = a[i] - minimum;
            a[i] = a[i] - minimum;
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
    selectionSort(a, 0, max);
    for (int i=0; i<max; i++) {
       cout<<a[i]<<",";
    }
    cout<<endl;
    return 0;
}
