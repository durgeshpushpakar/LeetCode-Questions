#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
class Solution {
public:
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    if(root==NULL)return ans;
    queue<TreeNode*>q;
    q.push(root);
    bool flag=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>temp;
        while(size--){
            TreeNode*front=q.front();
            q.pop();
            temp.push_back(front->val);
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
        if(!flag)reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        flag=!flag;
    }
    return ans; 
}
};
int main()
{

    return 0;
}