// https://leetcode.com/problems/add-two-numbers/
#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
 
class Solution {
public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head=NULL, *tail=NULL;
    int carry=0;
    while(l1!=NULL && l2!=NULL){
        int sum=l1->val+l2->val+carry;
        carry=sum/10;
        ListNode*newNode=new ListNode(sum%10);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        l1=l1->next;
        l2=l2->next;
    }
    while(l1!=NULL){
        int sum=l1->val+carry;
        carry=sum/10;
        ListNode*newNode=new ListNode(sum%10);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        l1=l1->next;
    }
    while(l2!=NULL){
        int sum=l2->val+carry;
        carry=sum/10;
        ListNode*newNode=new ListNode(sum%10);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        l2=l2->next;
    }
    if(carry!=0){
        ListNode*newNode=new ListNode(carry);
        tail->next=newNode;
        tail=newNode;
    }
    return head;
}
};

int main()
{

    return 0;
}