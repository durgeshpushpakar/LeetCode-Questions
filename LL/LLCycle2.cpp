// https://leetcode.com/problems/linked-list-cycle-ii/
// O O O O
#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
class Solution {
public:
ListNode *detectCycle(ListNode *head) {
    ListNode *slow=head, *fast=head;
    if(head==NULL)return NULL;
    while(fast!=NULL &&slow!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)break;
    }
    if(fast==NULL || slow==NULL || fast->next==NULL)return NULL;
    slow=head;
    while(slow!=NULL && fast!=NULL){
        if(slow==fast)return slow;
        slow=slow->next;
        fast=fast->next;
    }
}
};