#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
class Solution {
public:
ListNode* swapPairs(ListNode* head) {
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;
    ListNode*head2=head->next->next;
    head->next->next=NULL;
    ListNode*smallHead=swapPairs(head2);
    ListNode*nxt=head->next;
    nxt->next=head;
    head->next=smallHead;
    return nxt;
}
};
int main()
{

    return 0;
}