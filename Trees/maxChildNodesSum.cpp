#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class NodeSum{
    public:
    TreeNode<int> *node;
    int sum;
    NodeSum(TreeNode<int> *node, int sum){
        this->node=node;
        this->sum=sum;
    }
};
NodeSum helper(TreeNode<int>*root){
    if(root==NULL){
        NodeSum temp(NULL, INT_MIN);
        return temp;
    };
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }
    NodeSum highest(root, sum);
    for(int i=0;i<root->children.size();i++){
        NodeSum temp=helper(root->children[i]);
        if(temp.sum>highest.sum)highest=temp;        
    }
    return highest;
}
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    return helper(root).node;
}