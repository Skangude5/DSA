//
//  circular_linkedlist.cpp
//  Data Structure Algorithms
//
//  Created by Sharad Kangude on 02/12/20.
//

#include <iostream>
using namespace std;

class Node{
public:
    int key,data;
    Node* next;
    Node(){
        this->key = 0;
        this->data = 0;
        this->next = NULL;
    }
    Node(int k, int d){
        this->key = k;
        this->data = d;
        this->next = NULL;
    }
};
class CircularLinkedList{
public:
    Node* head;
    CircularLinkedList(){
        this->head = NULL;
    }
    CircularLinkedList(Node *n){
        this->head = n;
        this->head->next = n;
    }
    Node* nodeExists(int k){
        Node* ptr = this->head;
        do{
            if (ptr->key==k) {
                return ptr;
            } else {
                ptr = ptr->next;
            }
        }while (ptr!=this->head);
        return NULL;
    }
    void appendNode(Node *n){
         if (this->head==NULL) {
            this->head = n;
            this->head->next = n;
            cout<<"Node appended."<<endl;
        }else {
            if (nodeExists(n->key)!= NULL) {
                cout<<"Node already exists with key value :"<<n->key<<". Append another node with different key value"<<endl;
            }
             else {
                Node* ptr = this->head;
                while (ptr->next!=this->head){
                    ptr = ptr->next;
                }
                n->next = ptr->next;
                ptr->next = n;
                cout<<"Node appended."<<endl;
            }
        }
    }
    void prependNode(Node *n){
         if (this->head==NULL) {
              this->head = n;
              this->head->next = n;
              cout<<"Node appended."<<endl;
        } else {
            if (nodeExists(n->key)!= NULL) {
                cout<<"Node already exists with key value :"<<n->key<<". Append another node with different key value"<<endl;
            }
           else {
              Node* ptr = this->head;
              while (ptr->next!=this->head) {
                  ptr = ptr->next;
              }
              ptr->next = n;
              n->next = this->head;
              this->head = n;
              cout<<"Node prepended."<<endl;
          }
        }
    }
    void insertNode(int k, Node *n){
        Node* ptr = this->nodeExists(k);
        if (ptr==NULL) {
            cout<<"No  node with key value : "<<k<<endl;
        } else {
            if (this->nodeExists(n->key)!=NULL) {
                cout<<"Node already exists with key value :"<<n->key<<". Append another node with different key value"<<endl;
            } else {
                    n->next = ptr->next;
                    ptr->next = n;
                    cout<<"Node inserted."<<endl;
            }
        }
    }
    void deleteNode(int k){
        if (this->head==NULL) {
            cout<<"Circular Linked List Empty!"<<endl;
        } else {
            Node* ptr = nodeExists(k);
            if (ptr!=NULL) {
                if (ptr==this->head) {
                    if (this->head->next==this->head) {
                        this->head = NULL;
                        cout<<"Node unlinked & link is empty now."<<endl;
                    } else {
                        Node* ptr = this->head;
                        while (ptr->next!=this->head) {
                            ptr = ptr->next;
                        }
                        ptr->next = head->next;
                        this->head = ptr->next;
                        cout<<"Node unlinked."<<endl;
                    }
                } else {
                    Node* temp = NULL;
                    Node* prevptr = this->head;
                    Node* currentptr = this->head->next;
                    while (currentptr!=this->head) {
                        if (currentptr->key==k) {
                            temp = currentptr;
                            currentptr = this->head;
                        } else {
                            prevptr = currentptr;
                            currentptr = currentptr->next;
                        }
                    }
                    if (temp!=this->head) {
                        prevptr->next = temp->next;
                        cout<<"Node unlinked with key value : "<<k<<endl;
                    } else {
                        cout<<"Node doesn't exist with key value : "<<k<<endl;
                    }
                }
            } else {
                cout<<"Node doesn't exist with key value : "<<k<<endl;
            }
        }
    }
    void updateNode(int k, int d){
        if (this->head==NULL) {
            cout<<"Circular Linked List Empty!"<<endl;
        } else {
        Node* ptr = nodeExists(k);
        if (ptr!=NULL) {
            ptr->data = d;
            cout<<"Node data updated successfully."<<endl;
        } else {
            cout<<"Node doesn't exist with key value : "<<k<<endl;
        }
        }
    }
    void printList(){
        if (this->head==NULL) {
            cout<<"No node in doubly linked list."<<endl;
        } else {
            cout<<endl<<"Doubly Linked List Values : ";
            Node* temp = this->head;
            do{
                cout<<"("<<temp->key<<","<<temp->data<<") -->";
                temp = temp->next;
            }while (temp!=this->head);
        }
    }
};
int main(){
    CircularLinkedList s;
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
