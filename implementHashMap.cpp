#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int key;
    int data;
    Node * next;
    Node(int k, int d){
        data=d;
        key=k;
        next=NULL;
    }
    ~Node(){
        delete next;
    }
};
class MyHashMap {

    Node **buckets;
    int size;
    int numBuckets;

public:
    MyHashMap() {
        numBuckets=5;
        buckets=new Node*[numBuckets];
        for(int i=0;i<numBuckets;i++){
            buckets[i]=NULL;
        }
    }
    ~MyHashMap(){
        for(int i=0;i<numBuckets;i++){
            delete buckets[i];
        }
        delete [] buckets;
    }
    void put(int key, int value) {
        int idx=key%numBuckets;
        if(buckets[idx]==NULL){
            Node* newNode=new Node(key, value);
            buckets[idx]=newNode;
        }
        else{
            Node *head=buckets[idx];
            while(head->next!=NULL)head=head->next;
            Node* newNode=new Node(key, value);
            head->next=newNode;
        }
    }
    
    int get(int key) {
        int idx=key%numBuckets;
        Node* temp=buckets[idx];
        if(temp==NULL)return -1;
        while(temp!=NULL){
            if(temp->key==key)return temp->data;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx=key%numBuckets;
        Node* temp=buckets[idx];
        if(temp==NULL)return;
        if(temp->next==NULL && temp->key==key){
            delete temp;
            temp=NULL;
            return ;
        }
        Node*prev=temp;
        while(temp!=NULL){
            temp=temp->next;
            if(temp->key==key){
                prev->next=temp->next;
                delete temp;
            }
            prev=temp;
        }
        return;
    }
};
int main()
{
    int *arr=new int (5);
    for(int i=0;i<5;i++){
        arr[i]=i;
        cout<<arr[i]<<" ";
    }
    return 0;
}