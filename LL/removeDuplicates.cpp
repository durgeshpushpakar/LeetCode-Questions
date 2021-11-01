#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
class Solution {
public:
ListNode* deleteDuplicates(ListNode* head) {
    ListNode*temp=head, *prev=NULL;
    while(temp!=NULL && temp->next!=NULL){
        while(temp->val==temp->next->val){
            temp=temp->next;
        }
        if(prev==NULL){
            head=temp->next;
        }
        else{
            prev->next=temp->next;
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