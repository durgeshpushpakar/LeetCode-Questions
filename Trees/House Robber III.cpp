// https://leetcode.com/problems/house-robber-iii/
#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
class Pair{
public: 
int inc, exc;
Pair(int i, int e){
    inc=i;
    exc=e;
}
};
class Solution {
public:
Pair helper(TreeNode *root){
    if(root==NULL){
        Pair ans(0, 0);
        return ans;
    }
    Pair leftAns=helper(root->left);
    Pair rightAns=helper(root->right);
    int incAns = root->val + leftAns.exc + rightAns.exc;
    int excAns = max(leftAns.inc, leftAns.exc) + max(rightAns.inc, rightAns.exc);
    Pair ans(incAns, excAns);
    return ans;
}
int rob(TreeNode* root) {
    Pair ans=helper(root);
    return max(ans.inc, ans.exc);    
}
};
int main()
{

    return 0;
}