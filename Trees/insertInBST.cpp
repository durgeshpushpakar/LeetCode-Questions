#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root==NULL){
        TreeNode* newNode=new TreeNode(val);
        return newNode;
    }
    if(val>root->val)root->right=insertIntoBST(root->right, val);
    else root->left=insertIntoBST(root->left, val);
    return root;
}
int main()
{

    return 0;
}