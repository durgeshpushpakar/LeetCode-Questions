// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
class Solution {
public:
int longestZigZag(TreeNode* root, int flag=1) {
    if(root==NULL)return 0;
    if(flag==1)return longestZigZag(root->right, -1)+1;
    if(flag==-1)return longestZigZag(root->left, 1)+1;
    return 0;
}

};
int main()
{

    return 0;
}