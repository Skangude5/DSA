//
//  shell_sort.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 08/12/20.
//

#include <iostream>
using namespace std;

void shellSort(int arr[], int max){
    for (int gap=max/2; gap>0; gap/=2) {
        for (int j=gap; j<max; j++) {
            int temp = arr[j];
            int i=0;
            for (i=j;i>=gap && temp<arr[i-gap];i-=gap) {
                arr[i] = arr[i-gap];
            }
            arr[i] = temp;
        }
    }
}
int main(){
    int max=0;
          cout<<"Enter array size :";cin>>max;
    int a[max];
          cout<<"enter array element : ";
          for (int i=0; i<max; i++) {
              cin>>a[i];
          }
     shellSort(a, max);
       for (int i=0; i<max; i++) {
          cout<<a[i]<<",";
       }
       cout<<endl;
    return 0;
}
