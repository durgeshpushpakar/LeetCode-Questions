// https://leetcode.com/problems/search-in-a-binary-search-tree/
#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
TreeNode* searchBST(TreeNode* root, int val) {
    if(root==NULL)return NULL;
    if(root->val==val)return root;
    if(val>root->val)return searchBST(root->right, val);
    return searchBST(root->left, val);        
}
int main(){
    return 0;
}