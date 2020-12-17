//
//  singly_linkedlist.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 30/11/20.
//  Copyright © 2020 Sharad Kangude. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
public:
    Node* next;
    int key;
    int data;
    Node(){
        this->data=0;
        this->key=0;
        this->next=NULL;
    }
    Node(int k, int x){
        this->key = k;
        this->data = x;
        this->next=NULL;
    }
};
class SinglyLinkedList{
public:
    Node* head;
    SinglyLinkedList(){
        this->head = NULL;
    }
    SinglyLinkedList(Node *n){
        this->head = n;
    }
    Node* nodeExists(int k){
        Node* ptr = this->head;
        while (ptr!=NULL) {
            if (ptr->key==k) {
                return ptr;
            }
            ptr = ptr->next;
        }
        return NULL;
    }
    void appendNode(Node *n){
        if (nodeExists(n->key)!=NULL) {
            cout<<"Node already exists with key value :"<<n->key<<". Append another node with different key value"<<endl;
        } else {
            if (this->head==NULL) {
                this->head = n;
                cout<<"Node appended."<<endl;
            } else {
                Node* ptr = this->head;
                while (ptr->next!=NULL) {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout<<"Node appended."<<endl;
            }
        }
    }
    void prependNode(Node *n){
        if (nodeExists(n->key)!=NULL) {
            cout<<"Node already exists with key value :"<<n->key<<". Append another node with different key value"<<endl;
        } else {
                n->next = this->head;
                this->head = n;
                cout<<"Node appended."<<endl;
        }
    }
    void insertNode(int k, Node *n){
        Node* ptr = this->nodeExists(k);
        if (ptr==NULL) {
            cout<<"No node exists with key value: "<<k<<endl;
        } else {
            if (nodeExists(n->key)!=NULL) {
                       cout<<"Node already exists with key value :"<<n->key<<". Append another node with different key value"<<endl;
            } else {
                n->next = ptr->next;
                ptr->next = n;
            }
        }
    }
    void deleteNode(int k){
        if (this->head==NULL) {
            cout<<"Singly Linked List already empty. Can't delete."<<endl;
        } else if(this->head!=NULL){
            if (this->head->key==k) {
                this->head = this->head->next;
                cout<<"Node UNLINKED with key value : "<<k<<endl;
            } else {
                Node* ptr = this->nodeExists(k);
                if (ptr==NULL) {
                    cout<<"No node exists with key value: "<<k<<endl;
                } else {
                    Node* temp = NULL;
                    Node* prevptr = this->head;
                    Node* currentptr = this->head->next;
                    while (currentptr!=NULL) {
                        if (currentptr->key==k) {
                            temp = currentptr;
                            currentptr = NULL;
                        } else {
                            prevptr = currentptr;
                            currentptr = currentptr->next;
                        }
                    }
                    if (temp!=NULL) {
                        prevptr->next = temp->next;
                        cout<<"Node unlinked with key value : "<<k<<endl;
                    } else {
                        cout<<"Node doesn't exist with key value : "<<k<<endl;
                    }
                }
            }
        }
    }
    void updateNode(int k, int d){
        Node* ptr = nodeExists(k);
        if (ptr!=NULL) {
            ptr->data = d;
            cout<<"Node data updated successfully."<<endl;
        } else {
            cout<<"Node doesn't exist with key value : "<<k<<endl;
        }
    }
    void printList(){
        if (this->head==NULL) {
            cout<<"No node in sigly linked list."<<endl;
        } else {
            cout<<endl<<"Singly Linked List Values : ";
            Node* temp = this->head;
            while (temp!=NULL) {
                cout<<"("<<temp->key<<","<<temp->data<<") -->";
                temp = temp->next;
            }
        }
    }
};
int main(){
    SinglyLinkedList s;
   int option,key1,k1,data1;
    do{
    cout<<endl<<"\n1. append node"<<endl
              <<"2. prepend node"<<endl
              <<"3. insert node after"<<endl
              <<"4. delete node by key"<<endl
              <<"5. update node by key"<<endl
              <<"6. print"<<endl
              <<"9. clear screen"<<endl
    <<"0. exit"<<endl<<"input :";cin>>option;
        Node* n1 = new Node();
        system("clear");
    switch (option) {
        case 0:
            cout<<"Exiting...."<<endl;
            break;
        case 1:
            cout<<"Append node operation\nEnter key & data of the node to be appended:";
            cin>>key1>>data1;
            n1->key=key1;n1->data=data1;
            s.appendNode(n1);
            break;
        case 2:
            cout<<"Prepend node operation\nEnter key & data of the node to be Prepended:";
            cin>>key1>>data1;
            n1->key=key1;n1->data=data1;
            s.prependNode(n1);
            break;
        case 3:
            cout<<"Insert node operation\nEnter key of existing node after which you want to insert node:";
            cin>>k1;
            cout<<"Enter key & data of new node :";
            cin>>key1>>data1;
            n1->key=key1;n1->data=data1;
            s.insertNode(k1, n1);
            break;
        case 4:
            cout<<"Delete node operation\nEnter key of the node to be delete:";
            cin>>k1;
            s.deleteNode(k1);
            break;
        case 5:
            cout<<"update node operation\nEnter key & new data of the node to be update:";
            cin>>k1>>data1;
            s.updateNode(k1, data1);
            break;
        case 6:
            s.printList();
            break;
        case 9:
            system("clear");
            break;
        default:
            cout<<"invalid choice."<<endl;
    }
    }while(option!=0);
    return 0;
}
