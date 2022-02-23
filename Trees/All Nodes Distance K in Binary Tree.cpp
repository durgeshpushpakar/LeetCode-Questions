#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
class Solution {
public:
vector<int>nodes;
void downNodes(TreeNode *root, int k){
    if(root==NULL)return;
    if(k==0){
        if(root!=NULL){
            nodes.push_back(root->val);
        }
    }
    downNodes(root->left, k-1);
    downNodes(root->right, k-1);
}
int helper(TreeNode *root, TreeNode *target, int k){
    if(root==NULL)return -1;
    if(root==target){
        downNodes(root, k);
        return 0;
    }
    int leftAns=helper(root->left, target, k);
    if(leftAns!=-1){
        if(leftAns+1==k){
            nodes.push_back(root->val);
            return leftAns+1;
        }
        if(leftAns+1<k){
            downNodes(root->right, k-leftAns-2);
            return leftAns+1;
        }
        if(leftAns+1>k)return leftAns+1;
    }
    
    int rightAns=helper(root->right, target, k);
    if(rightAns!=-1){
        if(rightAns+1==k){
            nodes.push_back(root->val);
            return rightAns+1;
        }
        if(rightAns+1<k){
            downNodes(root->left, k-rightAns-2);
            return rightAns+1;
        }
        if(rightAns+1>k)return rightAns+1;
    }
    return -1;
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if(target==NULL)return nodes;
    helper(root, target, k);
    return nodes;
}
};
int main()
{

    return 0;
}