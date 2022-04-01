// https://leetcode.com/problems/distribute-coins-in-binary-tree/

#include <bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
/*
class Solution{
public:
int helper(TreeNode *root, int &op){
    if (root == NULL) return 0;
    int left = helper(root->left, op);
    int right = helper(root->right, op);
    int surplus = root->val + left + right -1;
    op += abs(surplus);
    return surplus;
}

int distributeCoins(TreeNode *root){
    int op = 0;
    int x = helper(root, op);
    return op;
}
};
*/
class Pair{
    public:
    int op, surplus;
    Pair(int o, int s){
        op=o; surplus=s;
    }
};
Pair helper(TreeNode *root){
    if(root==NULL){
        Pair ans(0, 0);
        return ans;
    }
    Pair left = helper(root->left);
    Pair right = helper(root->right);

    int surplus = root->val + left.surplus + right.surplus - 1;
    int operations = abs(surplus) + left.op + right.op;
    Pair ans(operations, surplus);
    return ans;     
}
int distributeCoins(TreeNode *root){
    return helper(root).op;
}
