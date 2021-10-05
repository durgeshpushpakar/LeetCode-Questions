#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
int maxDepth(TreeNode* root) {
    if(root==NULL)return 0;
    if(root->left==NULL && root->right==NULL)return 1;
    int smallAns1=maxDepth(root->left);
    int smallAns2=maxDepth(root->right);
    return max(smallAns1, smallAns2)+1;
}
int main()
{

    return 0;
}