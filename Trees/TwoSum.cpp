// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
void preOrderTraversal(TreeNode *root, vector<int>&preOrder){
    if(root==NULL)return;
    preOrder.push_back(root->val);
    preOrderTraversal(root->left, preOrder);
    preOrderTraversal(root->right, preOrder);
}
bool findTarget(TreeNode* root, int k) {
    vector<int>preOrder;
    preOrderTraversal(root, preOrder);
    unordered_map<int, int>freq;
    for(int i=0;i<preOrder.size();i++)freq[preOrder[i]]++;
    for(int i=0;i<preOrder.size();i++){
        if(k-preOrder[i]==preOrder[i]){
            freq[preOrder[i]]--;
        }
        if(freq[k-preOrder[i]]>=1)return true;
    }
    return false;
}
int main()
{

    return 0;
}