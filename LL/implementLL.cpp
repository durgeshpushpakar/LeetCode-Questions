#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class MyLinkedList {
public:
    ListNode*head;
    MyLinkedList() {
        head=NULL;
    }
    
    int get(int index) {
        int i=0;
        ListNode *temp = head;
        while(temp != NULL){
            if(index == i) return temp->val;
            temp=temp->next;
            i++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode*temp=new ListNode(val);
        if(head==NULL){
            head=temp;
            return;
        }
        temp->next=head;
        head=temp;
    }
    
    void addAtTail(int val) {
        ListNode* newNode=new ListNode(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        ListNode* temp=head;
        while(temp->next!=NULL)temp=temp->next;
        temp->next=newNode;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* newNode=new ListNode(val);
        if(index==0){
            if(head==NULL)head=newNode;
            else{
                newNode->next=head;
                head=newNode;
                return;
            }
        }
        index--;
        ListNode*temp=head;
        while(temp!=NULL && index--){
            temp=temp->next;
        }
        if(temp==NULL)return;
        ListNode*nxt=temp->next;
        temp->next=newNode;
        newNode->next=nxt;
    }
    
    void deleteAtIndex(int index) {
        
    }
};
int main()
{

    return 0;
}