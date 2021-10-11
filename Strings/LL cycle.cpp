#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
bool hasCycle(ListNode *head) {
    ListNode *fast=head, *slow=head;
    if(head==NULL || head->next==NULL)return false;
    while(fast!=NULL && fast->next!=NULL &&slow!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)return true;
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
int main()
{

    return 0;
}