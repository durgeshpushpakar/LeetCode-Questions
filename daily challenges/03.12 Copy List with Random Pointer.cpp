#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
Node* copyRandomList(Node* head) {
    Node *temp=head, *head2=new Node(0), *t=head2;
    unordered_map<Node*, Node*>map;
    map.insert({NULL, NULL});
    while(temp!=NULL){
        Node *newNode= new Node(temp->val);
        map.insert({temp, newNode});
        t->next=newNode;
        t=newNode;
        temp=temp->next;
    }
    head2=head2->next;
    Node *temp2=head2;
    temp=head;
    while(temp && temp2){
        Node *randomNode=map[temp->random];
        temp2->random=randomNode;
        temp2=temp2->next;
        temp=temp->next;
    }
    return head2;
}
};