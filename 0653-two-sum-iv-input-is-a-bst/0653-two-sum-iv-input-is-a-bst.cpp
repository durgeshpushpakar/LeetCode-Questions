/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_set<int>set;
    bool helper(TreeNode*root, int k){
        if(root==NULL)return false;
        bool a=helper(root->left, k);
        if(set.find(k-root->val)!=set.end()){
            return true;
        }
        set.insert(root->val);
        bool b=helper(root->right, k);
        return a || b;
    }
    bool findTarget(TreeNode* root, int k) {
        return helper(root, k);
    }
};