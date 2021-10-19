#include<bits/stdc++.h>
using namespace std;
#include "TreeNode2.h"
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL)return NULL;
    if(root==p ||root==q)return root;
    else if(root->val<q->val && root->val<p->val)return lowestCommonAncestor(root->right, p, q);
    else if(root->val>q->val && root->val>p->val)return lowestCommonAncestor(root->left, p, q);
    return root;
}
int main()
{

    return 0;
}