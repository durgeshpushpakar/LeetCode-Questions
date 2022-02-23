#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
class Solution {
public:
vector<double> averageOfLevels(TreeNode* root) {
    queue<TreeNode*>q;
    q.push(root);
    vector<double>ans;
    while(!q.empty()){
        int size=q.size();
        double sum=0;
        for(int i=0;i<size;i++){
            TreeNode*front=q.front();
            q.pop();
            sum += front->val;
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
        double avg=sum/(double)size;
        ans.push_back(avg);
    }    
    return ans;
}
};
int main()
{

    return 0;
}