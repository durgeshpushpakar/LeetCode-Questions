// 1 1 2 3 3 4 4 5
// testcases to be taken care of
// 1 1 1
// 1 1 2 2
#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
class Solution {
public:
ListNode* deleteDuplicates(ListNode* head) {
    ListNode*temp=head, *prev=NULL;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->val==temp->next->val){
            while(temp!=NULL && temp->next!=NULL && temp->next->val==temp->val)temp=temp->next;
            if(temp->next==NULL){
                if(prev==NULL)return NULL;
                else{
                    prev->next=NULL;
                    return head;
                }
            }
            else if(prev==NULL){
                head=temp->next;
                temp=temp->next;
                continue;
            }
            else{
                prev->next=temp->next;
                temp=temp->next;
                continue;
            }            
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
};
int main()
{

    return 0;
}