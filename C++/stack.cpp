//
//  stack_class.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 29/11/20.
//

#include <iostream>
using namespace std;

class Stack{
private:
    int Top;
    int arr[5];
public:
    Stack(){
        for (int i=0; i<5; i++) {
            this->arr[i] = 0;
        }
        Top = -1;
    }
    void Push(int a){
        if (this->isFull()) {
            cout<<"Stack overflow!"<<endl;
        } else {
            this->Top++;
            this->arr[Top] = a;
        }
    }
    int pop(){
        int temp=0;
        if (this->isEmpty()) {
            cout<<"Stack underflow!, returning null"<<endl;
        } else {
            temp = this->arr[this->Top];
            this->arr[Top] = 0;
            this->Top--;
        }
        return temp;
    }
    bool isEmpty(){
        if (this->Top<0) {
            return true;
        } else {
            return false;
        }
    }
    bool isFull(){
        if (this->Top>3) {
            return true;
        } else {
            return false;
        }
    }
    int peek(int p){
        if (this->Top>p-2) {
            return this->arr[p-1];
        } else {
            cout<<"No element present at "<<p<<" position"<<endl;
            return 0;
        }
    }
    int count(){
        return this->Top+1;
    }
    void change(int x, int p){
        if (this->Top>p-2) {
            this->arr[p-1] = x;
        } else {
            cout<<"No element present at "<<p<<" position"<<endl;
        }
    }
    void display(){
        cout<<"Displaying Stack..."<<endl<<endl;
        for (int i=4; i>=0; i--) {
            cout<<"| "<<this->arr[i]<<" |"<<endl;
        }
        cout<<"--------"<<endl;
    }
};

int main(){
    int x,temp1,temp2;Stack stack;
    do {
    cout<<endl<<"\n1. display stack"<<endl
              <<"2. push element"<<endl
              <<"3. pop element"<<endl
              <<"4. peek element"<<endl
              <<"5. change element"<<endl
              <<"6. count of stack"<<endl
              <<"7. isEmpty"<<endl
              <<"8. isFull"<<endl
              <<"9. clear screen"<<endl
    <<"0. exit"<<endl<<"input :";cin>>x;
        //system("clear");
        cout<<"\033[2J\033[1;1H"<<flush;
    switch (x) {
        case 0:
            cout<<"Exiting...."<<endl;
            break;
        case 1:
            stack.display();
            break;
        case 2:
            cout<<"Enter Element to add:";cin>>temp1;
            stack.Push(temp1);
            break;
        case 3:
            cout<<"Popped element is :"<<stack.pop()<<endl;
            break;
        case 4:
            cout<<"Enter position to peek:";cin>>temp1;
            cout<<"element is : "<<stack.peek(temp1)<<endl;
            break;
        case 5:
            cout<<"Enter new Element & position:";cin>>temp1>>temp2;
            stack.change(temp1, temp2);
            break;
        case 6:
            cout<<"Number of elements in stack :"<<stack.count()<<endl;
            break;
        case 7:
            cout<<"isEmpty : "<<stack.isEmpty()<<endl;
            break;
        case 8:
            cout<<"isFull : "<<stack.isFull()<<endl;
            break;
        case 9:
//            system("clear");
            cout<<"\033[2J\033[1;1H"<<flush;
            break;
        default:
            cout<<"invalid choice."<<endl;
    }
    }while(x!=0);
    return 0;
}
