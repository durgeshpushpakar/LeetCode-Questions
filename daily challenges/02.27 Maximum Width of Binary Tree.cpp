#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
// class Pair{
//     public:
//     TreeNode*node;
//     int idx;
//     Pair(TreeNode*n, int i){
//         idx=i;
//         node=n;
//     }
// };
class Solution {
public:
int widthOfBinaryTree(TreeNode* root) {
    if(root==NULL)return 0;
    queue<pair<TreeNode*, int>>pending;
    pending.push(make_pair(root, 0));
    long ans = 1;
    while(!pending.empty()){
        int size = pending.size();
        long f = pending.front().second, b = pending.back().second;
        ans=max(ans, b-f+1);
        while(size--){
            pair<TreeNode*, int> front=pending.front();
            pending.pop();

            // we can also subtract f from it because at a time we are onlu interested in one level and to avoid integer overflow
            long idx = front.second;   
            TreeNode *frontNode = front.first;
            if(frontNode->left){
                pair<TreeNode*, int> temp2(frontNode->left, (2*idx)+1);
                pending.push(temp2);
            }
            if(frontNode->right){
                pair<TreeNode*, int> temp2(frontNode->right, (2*idx)+2);
                pending.push(temp2);
            }
        }        
    }
    return ans;
}
};