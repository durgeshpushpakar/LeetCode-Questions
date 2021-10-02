#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head==NULL)return NULL;
    if(head->next==NULL){
        if(n==1){
            delete head;
            return NULL;
        }
        else return head;
    }
    ListNode* temp1=head;
    ListNode* temp2=head;
    while(n-- && temp2!=NULL)temp2=temp2->next;
    //n>length
    if(n!=-1)return head;
    if(temp2==NULL){
        //remove head
        ListNode* nxt=head->next;
        delete head;
        return nxt;
    }

    while(temp2->next!=NULL){
        temp2=temp2->next;
        temp1=temp1->next;
    }
    // remove the node next to temp1 
    ListNode* nxt=temp1->next;
    temp1->next=nxt->next;
    delete nxt;
    return head;
}

int main()
{

    return 0;
}