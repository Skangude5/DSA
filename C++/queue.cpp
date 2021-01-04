//
//  queue_class.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 29/11/20.
//

#include <iostream>
using namespace std;

class Queue{
    int Front,Rear;
    int arr[5];
public:
    Queue(){
        this->Front=this->Rear=-1;
        for (int i=0; i<5; i++) {
            this->arr[i]=0;
        }
    }
    bool isEmpty(){
        if (this->Front==-1 && this->Rear==-1) {
            return true;
        } else{
            return false;
        }
    }
    bool isFull(){
        if (this->Rear==3) {
            return true;
        } else{
            return false;
        }
    }
    int count(){
        return this->Rear-this->Front+1;
    }
    void enqueue(int x){
        if (this->isFull()) {
            cout<<"Queue is full!"<<endl;
        } else if (this->isEmpty()){
            this->Front=this->Rear=0;
            this->arr[Rear]=x;
        } else {
            this->Rear++;
            this->arr[Rear]=x;
        }
    }
    int dequeue(){
        int temp=0;
        if (this->isEmpty()) {
            cout<<"Queue is Empty!"<<endl;
        } else if(this->Front==this->Rear){
            temp = this->arr[this->Rear];
            this->arr[this->Rear]=0;
            this->Front=this->Rear=-1;
            return temp;
        } else {
            temp = this->arr[this->Front];
            this->arr[this->Front]=0;
            this->Front++;
            return temp;
        }
        return temp;
    }
    void display(){
        cout<<"Displaying Queue....."<<endl;
        for (int i = 0; i<4; i++) {
            cout<<this->arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    int x,temp1;Queue queue;bool isOn=true;
    while(isOn==true){
    cout<<endl<<"\n1. display queue"<<endl
              <<"2. enqueue element"<<endl
              <<"3. dequeue element"<<endl
              <<"4. count of stack"<<endl
              <<"5. isEmpty"<<endl
              <<"6. isFull"<<endl
              <<"9. clear screen"<<endl
    <<"0. exit"<<endl<<"input :";cin>>x;
        //system("clear");
        cout<<"\033[2J\033[1;1H"<<flush;
    switch (x) {
        case 0:
            cout<<"Exiting...."<<endl;
            isOn=false;
            break;
        case 1:
            queue.display();
            break;
        case 2:
            cout<<"Enter Element to enqueue:";cin>>temp1;
            queue.enqueue(temp1);
            break;
        case 3:
            cout<<"dequeued element is :"<<queue.dequeue()<<endl;
            break;
        case 4:
            cout<<"Number of elements in queue :"<<queue.count()<<endl;
            break;
        case 5:
            cout<<"isEmpty : "<<queue.isEmpty()<<endl;
            break;
        case 6:
            cout<<"isFull : "<<queue.isFull()<<endl;
            break;
        case 9:
            //system("clear");
            cout<<"\033[2J\033[1;1H"<<flush;
            break;
        default:
            cout<<"invalid choice."<<endl;
    }
    }
    return 0;
}
