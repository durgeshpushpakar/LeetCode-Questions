#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
/*
class Solution {
public:

    ListNode *mergeLL(ListNode *head1, ListNode *head2){
        ListNode *h, *t;
        if(head1==NULL)return head2;
        if(head2==NULL)return head1;
        if(head1->val<head2->val){
            h=head1;
            t=head1;
            head1=head1->next;
        }
        else{
            h=head2;
            t=head2;
            head2=head2->next;
        }
        while(head1!=NULL && head2!=NULL){
            if(head1->val<head2->val){
                t->next=head1;
                t=t->next;
                head1=head1->next;
            }
            else{
                t->next=head2;
                t=t->next;
                head2=head2->next;
            }
        }
        if(head1!=NULL)t->next=head1;
        if(head2!=NULL)t->next=head2;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        ListNode *head=lists[0];
        for(int i=1;i<lists.size();i++){
            head=mergeLL(head, lists[i]);
        }
        return head;
    }
    
};
*/
class myCompare{
    public:
    bool operator()(ListNode *a, ListNode*b){
        return a->val>b->val;
    }
};
class Solution {
public:
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, myCompare>minHeap;
    ListNode *head=new ListNode(0);
    ListNode *tail=head;
    for(int i=0;i<lists.size();i++){
        if(lists[i]!=NULL)
            minHeap.push(lists[i]);
    }
    while(!minHeap.empty()){
        ListNode *top=minHeap.top();
        minHeap.pop();
        ListNode *newNode=new ListNode(top->val);
        tail->next=newNode;
        tail=tail->next;
        if(top->next!=NULL){
            minHeap.push(top->next);
        }
    }
    return head->next;
}
};
int main()
{

    return 0;
}