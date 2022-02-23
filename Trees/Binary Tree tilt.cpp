// https://leetcode.com/problems/binary-tree-tilt/
#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
class Pair{
    public:
    int sum, tiltSum;
    Pair(){}
    Pair(int s, int t){
        sum=s;
        tiltSum=t;
    }
};
class Solution {
public:
Pair helper(TreeNode *root){
    if(root==NULL){
        Pair ans(0, 0);
        return ans;
    }
    Pair leftAns = helper(root->left);
    Pair rightAns = helper(root->right);
    int sum = leftAns.sum + rightAns.sum + root->val;
    int tilt = leftAns.tiltSum + rightAns.tiltSum + abs(leftAns.sum - rightAns.sum);
    Pair ans(sum, tilt);
    return ans;
}
int findTilt(TreeNode* root) {
    return helper(root).tiltSum;
}
};
int main()
{

    return 0;
}