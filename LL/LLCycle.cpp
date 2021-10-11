#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
bool hasCycle(ListNode *head) {
    ListNode *slow=head;
    ListNode *fast=head;
    if(head->next==NULL)return false;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)return true;
    }   
    return false;
}
ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return nullptr;
        ListNode *fast = head, *slow = head;
        while(fast && fast->next && slow) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                fast = head;
                while (fast != slow) {                    
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
}
int main(){

    return 0;
}