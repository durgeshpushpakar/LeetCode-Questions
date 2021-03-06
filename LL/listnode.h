#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printLL(ListNode*head){
    ListNode* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" -> ";
        temp=temp->next;
    }
    cout<<endl;
}
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
