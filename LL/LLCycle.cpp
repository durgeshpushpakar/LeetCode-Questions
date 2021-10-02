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
int main(){

    return 0;
}