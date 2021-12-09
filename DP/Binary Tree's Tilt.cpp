// https://leetcode.com/problems/binary-tree-tilt/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Pair{
    public:
    int nodesSum;
    int tSum; // tilt sum
    Pair(){}
    Pair(int n, int t){
        nodesSum=n;
        tSum=t;
    }
};
class Solution {
public:
Pair helper(TreeNode*root){
    if(root==NULL){
        Pair ans(0, 0);
        return ans;
    }
    if(root->left==NULL && root->right==NULL){
        Pair ans(root->val, 0);
        return ans;
    }
    Pair leftAns=helper(root->left);
    Pair rightAns=helper(root->right);
    int sNodes=leftAns.nodesSum+rightAns.nodesSum+root->val;
    int rootTilt=abs(leftAns.nodesSum-rightAns.nodesSum);
    int sTilt=rootTilt + leftAns.tSum + rightAns.tSum;
    Pair ans(sNodes, sTilt);
    return ans;
}
int findTilt(TreeNode* root) {
    return helper(root).tSum;    
}
};