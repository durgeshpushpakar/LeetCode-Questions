#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
TreeNode* invertTree(TreeNode* root) {
    if(root==NULL)return NULL;        
    TreeNode* left=invertTree(root->left);
    TreeNode* right=invertTree(root->right);
    root->left=right;
    root->right=left;
    return root;
}

int main()
{

    return 0;
}