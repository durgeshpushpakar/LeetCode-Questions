#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL || p==root||q==root)return root;
    TreeNode*leftAns=lowestCommonAncestor(root->left, p, q);
    TreeNode*rightAns=lowestCommonAncestor(root->right, p, q);
    if(leftAns!=NULL && rightAns!=NULL)return root;
    else if(leftAns)return leftAns;
    return rightAns;
}   
int main()
{

    return 0;
}