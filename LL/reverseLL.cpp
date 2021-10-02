#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
ListNode* reverseList(ListNode* head) {
    ListNode* prev=NULL;
    ListNode* temp=head;
    ListNode* nxt;
    while(temp!=NULL){
        nxt=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nxt;
    }
    return prev;

}
int main(){

    return 0;
}