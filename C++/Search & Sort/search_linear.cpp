//
//  linear_search.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 03/12/20.
//

#include <iostream>
using namespace std;
 
int linearSearch(int a[],int max, int n){
    for(int i=0; i<max; i++){
        if (a[i]==n) {
            return i+1;
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
        int temp = linearSearch(a, max, n);
        if (temp==-1) {
            cout<<"No element found"<<endl;
        } else {
            cout<<n<<" is at "<<temp<<" position."<<endl;
        }
        
    } while (n!=-10);
    return 0;
}
