#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;

class Solution {
public:

ListNode*middle(ListNode *head){
    ListNode *slow=head, *fast=head;
    if(slow==NULL || fast==NULL)return NULL;
    if(fast->next->next==NULL)return slow;
    while((!fast->next) && (!fast->next->next)){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode *mergeLL(ListNode *head1, ListNode *head2){
    ListNode *fh=new ListNode(0), *ft=fh;
    while(head1!=NULL && head2!=NULL){
        if(head1->val<head2->val){
            ft->next=head1;
            ft=ft->next;
            head1=head1->next;
        }
        else {
            ft->next=head2;
            ft=ft->next;
            head2=head2->next;
        }
    }
    if(head1!=NULL)ft->next=head1;
    if(head2!=NULL)ft->next=head2;
    return fh->next;
}
ListNode* sortList(ListNode* head) {
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;
    
    ListNode*mid=middle(head);
    ListNode *head1=head, *head2=mid->next;
    mid->next=NULL;
    ListNode *h1=sortList(head1);
    ListNode *h2=sortList(head2);
    return mergeLL(h1, h2);
}
};