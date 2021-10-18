// https://leetcode.com/problems/validate-binary-search-tree/
#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
class Pair{
    public:
    int maxNode;
    int minNode;
    bool isValid;
    Pair(){
        maxNode=INT_MIN;
        minNode=INT_MAX;
        isValid=true;
    }
};

Pair helper(TreeNode*root){
    Pair ans;
    if(root==NULL){
        ans.isValid=true;
        return ans;
    }
    Pair smallAns1=helper(root->left);
    Pair smallAns2=helper(root->right);

    ans.maxNode=max(root->val, max(smallAns1.maxNode, smallAns2.maxNode));
    ans.minNode=min(root->val, min(smallAns1.minNode, smallAns2.minNode));
    ans.isValid=smallAns1.isValid && smallAns2.isValid && root->val>smallAns1.maxNode&&root->val<smallAns2.minNode;
    return ans; 
}

bool helper2(TreeNode* root, long minimum=LONG_MIN, long maximum=LONG_MAX){
    if(root==NULL)return true;
    if(root->val>=maximum || root->val<=minimum)return false;
    //conditions for INT_MIN and INT_MAX   
    return helper2(root->left, minimum, (int)root->val) && helper2(root->right, (int)root->val, maximum);
}
bool isValidBST(TreeNode* root){
    return helper2(root);
}
/*
class Solution {
  public boolean isValidBST(TreeNode root) {
    if (root == null) {
      return false;
    }
    if ((root.val == Integer.MIN_VALUE && root.left != null) || (root.val == Integer.MAX_VALUE && root.right != null)) {
      return false;
    }
    return isValidBST(root.left, Integer.MIN_VALUE, root.val - 1) 
      && isValidBST(root.right, root.val + 1, Integer.MAX_VALUE);
  }
  
  // min and max are inclusive
  private boolean isValidBST(TreeNode node, int min, int max) {
    if (node == null) {
      return true;
    }
    if (node.val < min || node.val > max) {
      return false;
    }
    if ((node.val == Integer.MIN_VALUE && node.left != null) || (node.val == Integer.MAX_VALUE && node.right != null)) {
      return false;
    }
    return isValidBST(node.left, min, node.val - 1) 
      && isValidBST(node.right, node.val + 1, max);
  }
}
*/
int main()
{

    return 0;
}