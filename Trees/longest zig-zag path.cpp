#include<bits/stdc++.h>
#include "TreeNode2.h"
#define pairi pair<int, int>
using namespace std;
class Solution {
public:
    int maxAns=0;
    void helper(TreeNode *root, bool isLeft, int ans){
        if(root==NULL){
            maxAns=max(ans, maxAns);
            return;
        }
        if(isLeft){
            helper(root->left, false, ans+1);
            helper(root->right, true, 0);
        }
        else{
            helper(root->right, true, ans+1);
            helper(root->left, false, 0);
        }
    }
    int longestZigZag(TreeNode* root) {
        helper(root->left, false, 0);
        helper(root->right, true, 0);
        return maxAns;
    }
};