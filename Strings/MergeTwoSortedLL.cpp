#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* mergeTwoLists(ListNode *head1, ListNode *head2) {
    ListNode *fh, *ft;
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    if(head1->val<=head2->val){
        fh=head1;
        ft=head1;
        head1=head1->next;
    }
    else{
        fh=head2;
        ft=head2;
        head2=head2->next;
    }
    while(head1 && head2){
        if(head1->val<=head2->val){
            ft->next=head1;
            ft=ft->next;
            head1=head1->next;
        }
        else{
            ft->next=head2;
            ft=ft->next;
            head2=head2->next;
        }
    }
    if(head1==NULL){
        ft->next=head2;
    }
    if(head2==NULL){
        ft->next=head1;
    }
    return fh;
}
int main()
{

    return 0;
}