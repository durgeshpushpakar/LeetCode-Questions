#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;

class Solution {
public:
    int lengthLL(ListNode*head){
        ListNode*temp=head;
        int ans=0;
        while(temp!=NULL){
            temp=temp->next;
            ans++;
        }
        return ans;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n=lengthLL(head);
        if(n==0 || k==0)return head;
        k=k%n;
        if(k==0 || head==NULL || n==1 || k==n)return head;
        ListNode* temp=head;
        int x=1;
        while(x<n-k){
            temp=temp->next;
            x++;
        }
        ListNode *head2=temp->next;
        temp->next=NULL;
        ListNode *tail=head2;
        while(tail->next!=NULL)tail=tail->next;
        tail->next=head;
        return head2;
    }
};
int main()
{

    return 0;
}