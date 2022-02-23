// https://leetcode.com/problems/diameter-of-binary-tree/
#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;

class Solution {
public:    
int height(TreeNode *root){
    if(root==NULL)return 0;
    return max(height(root->left), height(root->right))+1;
}
int diameterOfBinaryTree(TreeNode* root) {
    if(root==NULL)return 0;
    int leftAns=diameterOfBinaryTree(root->left);
    int rightAns=diameterOfBinaryTree(root->right);
    return max(height(root->left)+height(root->right), max(leftAns, rightAns));
}
};
int main()
{

    return 0;
}