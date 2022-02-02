#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
class Solution {
public:
ListNode* oddEvenList(ListNode* head) {
    if(head==NULL ||head->next==NULL || head->next->next==NULL)return head;
    ListNode *evenHead=head->next, *odd=head, *even=head->next;
    while(even && even->next){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}
};
int main()
{

    return 0;
}