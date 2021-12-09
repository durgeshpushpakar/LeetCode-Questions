#include<bits/stdc++.h>
using namespace std;
/**
Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode(){
        delete left;
        delete right;
    }
};
class Solution {
public:
vector<TreeNode*> helper(int si, int ei){
    vector<TreeNode*>ans;
    if(si>ei){
        ans.push_back(NULL);
        return ans;
    }
    else if(si==ei){
        TreeNode *newNode=new TreeNode(si);
        ans.push_back(newNode);
        return ans;
    } 
    for(int i=si;i<=ei;i++){
        vector<TreeNode*>leftAns=helper(si, i-1);
        vector<TreeNode*>rightAns=helper(i+1, ei);
        int x=leftAns.size();
        int y=rightAns.size();
        for(int j=0;j<x;j++){
            for(int k=0;k<y;k++){
                TreeNode *root=new TreeNode(i);
                root->left=leftAns[j];
                root->right=rightAns[k];
                ans.push_back(root);
            }
        }
        //pushed back all possible trees with root as nodes[i]
    }
    return ans;
}
vector<TreeNode*> generateTrees(int n) {
    return helper(1, n);    
}
};