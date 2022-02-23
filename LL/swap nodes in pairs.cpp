#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
class Solution {
public:
ListNode* swapPairs(ListNode* head) {
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;
    ListNode *temp=head, *prev=NULL;
    while(temp!=NULL){
        ListNode *nxt=temp->next, *nxt2=nxt->next;
        if(prev==NULL){
            nxt->next=temp;
            temp->next=nxt2;
            head=nxt;
            prev=temp;
            temp=nxt2;
        }
        else{
            nxt->next=temp;
            temp->next=nxt2;
            prev->next=nxt;
            prev=temp;
            temp=nxt2;
        }
    }
    return head;   
}
};
int main()
{

    return 0;
}