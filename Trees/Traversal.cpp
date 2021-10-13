#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
vector<int> preorderTraversal(TreeNode* root) {
    vector<int>ans;
    if(root==NULL) return ans;        
    vector<int>left=preorderTraversal(root->left);
    vector<int>right=preorderTraversal(root->right);
    ans.push_back(root->val);
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    if(root==NULL)return ans;
    queue<TreeNode*>pending;
    pending.push(root);
    pending.push(NULL);
    vector<int>temp;
    temp.push_back(root->val);
    ans.push_back(temp);
    temp.clear();
    while(!(pending.size()==1 && pending.front()==NULL)){
        TreeNode *node=pending.front();
        if(node==NULL){
            pending.push(NULL);
            pending.pop();
            ans.push_back(temp);
            temp.clear();
            continue;
        }
        pending.pop();
        if(root->left){
            temp.push_back(root->left->val);
            pending.push(node->left);
        }
        if(root->right){
            temp.push_back(root->right->val);
            pending.push(node->right);
        }
        cout<<"durgesh"<<endl;
    }    
    return ans;    
}
int main()
{

    return 0;
}