#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
class Solution {
public:
int length(ListNode*head){
    ListNode*temp=head;
    int ans=0;
    while(temp!=NULL){
        ans++;
        temp=temp->next;
    }
    return ans;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int len1=length(headA);
    int len2=length(headB);
    ListNode*temp1=headA, *temp2=headB;
    if(len1>len2){
        int t=len1-len2;
        while(t--)temp1=temp1->next;
    }
    else{
        int t=len2-len1;
        while(t--)temp2=temp2->next;
    }
    while(temp1!=NULL && temp2!=NULL){
        if(temp1==temp2)return temp1;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return NULL;
}
};
int main()

{

    return 0;
}