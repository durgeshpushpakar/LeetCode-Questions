// https://classroom.codingninjas.com/app/classroom/me/5130/content/66469/offering/726966/problem/1581
#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int n) {
    if(root==NULL)return NULL;
    if(root->children.size()==0){
        if(root->data>n)return root;
        else return NULL;
    }
    int minimum=INT_MAX;
    TreeNode<int> *largestNode=NULL;
    if(root->data>n && root->data<minimum){
        minimum=root->data;
        largestNode=root;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int> *temp=getNextLargerElement(root->children[i], n);
        if(temp==NULL)continue;
        if(temp->data<minimum){
            minimum=temp->data;
            largestNode=temp;
        }                             
    }
    return largestNode;
}

int main(){

    return 0;
}