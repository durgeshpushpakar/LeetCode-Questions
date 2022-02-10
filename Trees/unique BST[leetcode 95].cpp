#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;

class Solution {
public:
vector<TreeNode*>helper(int s, int e){
    if(s>e)return {NULL};
    if(s==e){
        TreeNode*node=new TreeNode(s);
        return {node};
    }
    vector<TreeNode*>mainAns;
    for(int i=s;i<=e;i++){
        vector<TreeNode*>ans1=helper(s, i-1);
        vector<TreeNode*>ans2=helper(i+1, e);
        for(int k=0;k<ans1.size();k++){
            for(int j=0;j<ans2.size();j++){
                TreeNode *head=new TreeNode(i);
                head->left=ans1[k];
                head->right=ans2[j];
                mainAns.push_back(head);
            }
        }
    }
    return mainAns;
}
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};

int main()
{
    return 0;
}