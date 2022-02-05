#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
class Solution {
public:
    ListNode *reverseLL(ListNode*head){
        ListNode *prev=NULL, *temp=head, *nxt;
        while(temp!=NULL){
            nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)return true;
        if(head->next->next==NULL)return (head->val==head->next->val);
        ListNode*slow=head, *fast=head;
        while (fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *head1=head, *head2=slow->next;
        slow->next=NULL;
        head2=reverseLL(head2);
        while(head2!=NULL){
            if(head1->val!=head2->val)return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};
int main()
{

    return 0;
}