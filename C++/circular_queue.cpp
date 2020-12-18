//
//  circular_queue.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 29/11/20.
//

#include <iostream>
using namespace std;

class CircularQueue{
    int Front,Rear;
    int arr[5];
    int count_items;
public:
    CircularQueue(){
        this->Front=this->Rear=-1;this->count_items=0;
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
        if ((this->Rear+1)%4==this->Front) {
            return true;
        } else{
            return false;
        }
    }
    int count(){
        return this->count_items;
    }
    void enqueue(int x){
        if (this->isFull()) {
            cout<<"Queue is full!"<<endl;
            return;
        } else if (this->isEmpty()){
            this->Front=this->Rear=0;
            this->arr[Rear]=x;
        } else {
            this->Rear=(this->Rear+1)%4;
            this->arr[Rear]=x;
        }
        count_items++;
    }
    int dequeue(){
        int temp=0;
        if (this->isEmpty()) {
            cout<<"Queue is Empty!"<<endl;
            return temp;
        } else if(this->Front==this->Rear){
            temp = this->arr[this->Rear];
            this->arr[this->Rear]=0;
            this->Front=this->Rear=-1;
        } else {
            temp = this->arr[this->Front];
            this->arr[this->Front]=0;
            this->Front=(this->Front+1)%4;
        }
        count_items--;
        return temp;
    }
    void display(){
        cout<<"Displaying Queue....."<<endl;
        int temp = this->Front;
        for (int i = 0; i<this->count_items; i++) {
            cout<<this->arr[temp]<<" ";
            temp= (temp+1)%4;
        }
        cout<<endl;
    }
};
int main(){
    int x,temp1;CircularQueue cqueue;
    do {
    cout<<endl<<"\n1. display queue"<<endl
              <<"2. enqueue element"<<endl
              <<"3. dequeue element"<<endl
              <<"4. count of stack"<<endl
              <<"5. isEmpty"<<endl
              <<"6. isFull"<<endl
              <<"9. clear screen"<<endl
    <<"0. exit"<<endl<<"input :";cin>>x;
        system("clear");
    switch (x) {
        case 0:
            cout<<"Exiting...."<<endl;
            break;
        case 1:
            cqueue.display();
            break;
        case 2:
            cout<<"Enter Element to enqueue:";cin>>temp1;
            cqueue.enqueue(temp1);
            break;
        case 3:
            cout<<"dequeued element is :"<<cqueue.dequeue()<<endl;
            break;
        case 4:
            cout<<"Number of elements in queue :"<<cqueue.count()<<endl;
            break;
        case 5:
            cout<<"isEmpty : "<<cqueue.isEmpty()<<endl;
            break;
        case 6:
            cout<<"isFull : "<<cqueue.isFull()<<endl;
            break;
        case 9:
            system("clear");
            break;
        default:
            cout<<"invalid choice."<<endl;
    }
    }while(x!=0)
    return 0;
}

