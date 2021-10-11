#include<bits/stdc++.h>
using namespace std;
#include "listnode.h"
ListNode* removeElements(ListNode* head, int val) {
    if(head==NULL)return NULL;
    ListNode *nxt=head->next;
    head->next=NULL;
    ListNode *smallHead=removeElements(nxt, val);
    if(head->val==val){
        head->next=NULL;
        delete head;
        return smallHead;
    }
    else {
        head->next=smallHead;
        return head;
    }
}
ListNode* reverseList(ListNode* head) {
    ListNode *prev=NULL, *temp=head, *nxt;
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;
    while(temp!=NULL){
        nxt=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nxt;
    }
    return prev;
}
ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;
    ListNode *temp=head->next;
    while(temp!=NULL && temp->val==head->val){
        temp=temp->next;
    }
    temp=deleteDuplicates(temp);
    if(temp==NULL){
        head->next=NULL;
        return head;
    }
    head->next=temp;
    return head;    
}
int main()
{

    return 0;
}