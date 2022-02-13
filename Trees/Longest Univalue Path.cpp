#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
class Pair{
    public:
    bool isRootInvolved;
    int pathLen;
    Pair(int p, bool i){
        pathLen=p;
        isRootInvolved=i;
    }
};
class Solution {
public:
Pair helper(TreeNode *root){
    if(!root){
        Pair ans(-1, true);
        return ans;
    }
    if(!root->right && !root->left){
        Pair ans(1, true);
        return ans;
    }
    Pair leftAns=helper(root->left);
    Pair rightAns=helper(root->right);
    if(root->left && root->val==root->left->val){
        if(root->right && root->val==root->right->val){
            if(leftAns.isRootInvolved){
                if(rightAns.isRootInvolved){
                    Pair ans();
                }
                else{

                }
            }
        }
    }
}
int longestUnivaluePath(TreeNode* root) {
    return helper(root).pathLen;   
}
};
int main()
{

    return 0;
}