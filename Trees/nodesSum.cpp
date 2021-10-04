#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
int sumOfNodes(TreeNode<int>* root){
    int sum=0;
    for(int i=0;i<root->children.size();i++){
        sum+=sumOfNodes(root->children[i]);
    }
    sum+=root->data;
    return sum;
}
TreeNode<int>* maxDataNode(TreeNode<int> *root){
    //base case
    if(root==NULL)return NULL;
    TreeNode<int>*sample=new TreeNode<int>(INT_MIN);
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>*smallAns=maxDataNode(root->children[i]);
        if(smallAns->data>=sample->data)sample=smallAns;
    }
    if(root->data>=sample->data)sample=root;
    return sample;
}
