// https://leetcode.com/problems/range-sum-of-bst/submissions/
#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
class Solution {
public:
int rangeSumBST(TreeNode* root, int low, int high) {
    if(root==NULL)return 0;
    int x=rangeSumBST(root->left, low, high);
    int y=rangeSumBST(root->right, low, high);
    if(root->val<=high && root->val>=low)
        return x+y+root->val;
    return x+y;
}
};
int main()
{

    return 0;
}