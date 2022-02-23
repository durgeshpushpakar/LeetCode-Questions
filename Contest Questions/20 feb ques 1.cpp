#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
ListNode* mergeNodes(ListNode* head) {
    ListNode *h=head, *t=head->next;
    ListNode *newHead=new ListNode(0), *newTail=newHead;
    while(h && t){
        int sum=0;
        while(t && t->val!=0){
            sum+=t->val;
            t=t->next;
        }
        if(sum!=0){
            ListNode *newNode=new ListNode(sum);
            newTail->next=newNode;
            newTail=newNode;
        }
        h=t;
        t=t->next;
    }
    return newHead->next;
}
};