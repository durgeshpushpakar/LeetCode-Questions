#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
class Solution {
public:
TreeNode *helper(vector<int>&in, vector<int>&post, int inS, int inE, int postS, int postE){
    if(inE<inS || postS>postE)return NULL;
    int rootData=post[postE];
    TreeNode *root=new TreeNode(rootData);
    int linS, linE, lpostS, lpostE, rinS, rinE, rpostS, rpostE;
    linS=inS;
    rpostE=postE-1;
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
    lpostS=postS;
    lpostE=lpostS+linE-linS;
    rpostS=lpostE+1;

    TreeNode *leftRoot=helper(in, post, linS, linE, lpostS, lpostE);
    TreeNode *rightRoot=helper(in, post, rinS, rinE, rpostS, rpostE);
    root->left=leftRoot;
    root->right=rightRoot;
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n=inorder.size();
    return helper(inorder, postorder, 0, n-1, 0, n-1);
}
};
int main()
{

    return 0;
}