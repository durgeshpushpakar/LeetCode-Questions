#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
class Solution {
public:
    int lengthLL(ListNode*head){
        ListNode*temp=head;
        int ans=0;
        while(temp!=NULL){
            temp=temp->next;
            ans++;
        }
        return ans;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        int n=lengthLL(head);
        if(k==0)return {};
        if(head==NULL || n==0){
            vector<ListNode*>temp(k, NULL);
            return temp;
        }
        if(k>=n){
            int extras=k-n;
            ListNode *ptr1=head, *ptr2;
            while(ptr1!=NULL){
                ptr2=ptr1->next;
                ptr1->next=NULL;
                ans.push_back(ptr1);
                ptr1=ptr2;
            }
            while(extras--){
                ans.push_back(NULL);
            }
        }
        else{
            int subLength=n/k;
            int extras=n%k;
            ListNode *p1=head, *p2=head;
            while(p1!=NULL){
                int len=subLength;
                if(extras>0){
                    len++;
                    extras--;
                }
                int i=1;
                while(i!=len){
                    p2=p2->next;
                    i++;
                }
                ListNode *nextHead = p2->next;
                p2->next=NULL;
                ans.push_back(p1);
                p1=nextHead;
                p2=nextHead;
            }
        }
        return ans;
    }
};
int main(){

    return 0;
}