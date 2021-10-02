#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
bool isPalindrome(ListNode* head) {
    if(head->next==NULL)return true;
    if(head->next->next==NULL)return head->val==head->next->val;
    ListNode *slow=head, *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode *prev=NULL, *temp=slow, *nxt;
    while(temp!=NULL){
        nxt=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nxt;
    }        
    fast=head;
    while(prev!=NULL){
        if(prev->val!=fast->val)return false;
        prev=prev->next;
        fast=fast->next;
    }
    return true;
}
int main(){
    ListNode *h1=new ListNode(1);
    ListNode *h2=new ListNode(2);
    ListNode *h3=new ListNode(2);
    ListNode *h4=new ListNode(1);
    h1->next=h2;
    h2->next=h3;
    h3->next=h4;
    printLL(h1);
    cout<<isPalindrome(h1);
    return 0;
}