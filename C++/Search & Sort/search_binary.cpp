//
//  binary_search.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 03/12/20.
//

#include <iostream>
using namespace std;

int binarySearch(int a[], int max, int min, int n){
    while(min<=max){
        int mid = min + (max-min)/2;
        if (a[mid] == n) {
            return mid+1;
        } else if (a[mid]<n){
            min = mid + 1;
        } else{
            max = mid - 1;
        }
    }
    return -1;
}
int main(){
    int max,n;
    cout<<"Enter array size: ";cin>>max;
    int a[max];
    cout<<"enter array element : ";
    for (int i=0; i<max; i++) {
        cin>>a[i];
    }
    do {
        cout<<"Enter element to search(-10 to quit):";cin>>n;
        int temp = binarySearch(a, max, 0, n);
        if (temp==-1) {
            cout<<"No element found"<<endl;
        } else {
            cout<<n<<" is at "<<temp<<" position."<<endl;
        }
        
    } while (n!=-10);
    return 0;
}
