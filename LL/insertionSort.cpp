// https://leetcode.com/problems/insertion-sort-list/
#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
class Solution {
public:
ListNode* insertionSortList(ListNode* head){
    ListNode* temp=head, *nxt;
    while(temp && temp->next){
        ListNode *nxt=temp->next->next;
        ListNode *x=temp->next;
        if(x && x->val < temp->val){
            ListNode *prev2=NULL, *itr=head;
            while(itr && x->val > itr->val){
                prev2=itr;
                itr=itr->next;
            }
            temp->next=nxt;
            if(prev2){
                prev2->next=x;
                x->next=itr;
            }
            else{
                head=x;
                x->next=itr;
            }
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}
};  
int main()
{

    return 0;
}