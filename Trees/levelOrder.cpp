#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
/*CODING NINJAS SOLUTION*/
#include <queue>
void printLevelWise(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();
        if (frontNode == NULL)
        {
            cout << "\n";
            if (!pendingNodes.empty())
            {
                pendingNodes.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left != NULL)
            {
                pendingNodes.push(frontNode->left);
            }
            if (frontNode->right != NULL)
            {
                pendingNodes.push(frontNode->right);
            }
        }
    }
}
class Solution {
public:
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    if(root==NULL)return ans;
    queue<TreeNode*>q;
    q.push(root);
    vector<int>temp;    
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
        ans.push_back(temp);
    }
    return ans;    
}
};
int main()
{
    vector<int>arr={0,1,2,3,4,5,6};
    arr.erase(arr.begin(), arr.end());
    for(int x:arr)cout<<x<<' ';
    return 0;
}