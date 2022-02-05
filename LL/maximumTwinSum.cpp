// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
class Solution {
public:
ListNode *reverseLL(ListNode *head){
    ListNode *prev=NULL, *temp=head, *nxt;
    while(temp!=NULL){
        nxt=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nxt;
    }
    return prev;
}
int pairSum(ListNode* head) {
    if(head->next->next==NULL)return head->val+head->next->val;
    ListNode *slow=head, *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }    
    ListNode *head1=head, *head2=slow->next;
    slow->next=NULL;
    head2=reverseLL(head2);
    int maxSum=0;
    while(head1!=NULL && head2!=NULL){
        maxSum=max(maxSum, head1->val+head2->val);
        head1=head1->next;
        head2=head2->next;
    }
    return maxSum;
}
};
int main()
{

    return 0;
}