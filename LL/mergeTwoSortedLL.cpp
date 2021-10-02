#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
ListNode* mergeTwoLists(ListNode *head1, ListNode *head2) {
    ListNode *Fh, *Ft;
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    if(head1->val <= head2->val){
        Fh=head1;
        Ft=head1;
        head1=head1->next;
    }
    else{
        Fh=head2;
        Ft=head2;
        head2=head2->next;
    }
    while(!(head1==NULL || head2==NULL)){
        if(head1->val<=head2->val){
            Ft->next=head1;
            Ft=head1;
            head1=head1->next;
        }
        else{
            Ft->next=head2;
            Ft=head2;
            head2=head2->next;
        }
    }
    if(head1==NULL)Ft->next=head2;
    if(head2==NULL)Ft->next=head1;
    return Fh;
}
int main(){

    return 0;
}