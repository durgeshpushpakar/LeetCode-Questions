// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
class Solution {
public:
TreeNode *helper(vector<int>&pre, vector<int>&in, int preS, int preE, int inS, int inE){
    if(preE<preS || inE<inS)return NULL;
    TreeNode *root=new TreeNode(pre[preS]);
    int linS, linE, lpreS, lpreE, rpreS, rpreE, rinS, rinE;
    lpreS=preS+1;
    linS=inS;

    int rootData=pre[preS];
    int idx=0;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            idx=i;
            break;
        }
    }
    linE=idx-1;
    rinS=idx+1;
    rinE=inE;
    lpreE=lpreS+linE-linS;
    rpreS=lpreE+1;
    rpreE=preE;
    TreeNode *leftRoot=helper(pre, in, lpreS, lpreE, linS, linE);
    TreeNode *rightRoot=helper(pre, in, rpreS, rpreE, rinS, rinE);
    root->left=leftRoot;
    root->right=rightRoot;
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n=preorder.size();
    return helper(preorder, inorder, 0, n-1, 0, n-1);   
}
};
int main()
{

    return 0;
}