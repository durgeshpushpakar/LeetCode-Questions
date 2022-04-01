#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int, TreeNode*>createdNodes;
        // child->parent
        unordered_map<int, bool>isChild;
        for(auto x:desc){
            TreeNode* parent, *child;
            int parentVal=x[0], childVal=x[1];

            if(createdNodes.count(parentVal))parent=createdNodes[parentVal];
            else{
                parent=new TreeNode(parentVal);
                createdNodes.insert({parentVal, parent});
            }

            if(createdNodes.count(childVal))child=createdNodes[childVal];
            else{
                child=new TreeNode(childVal);
                createdNodes.insert({childVal, child});
            } 

            if(x[2]==1) parent->left=child;
            else parent->right=child;

            if(isChild.count(childVal)==0)isChild.insert({childVal, true});
        }
        for(auto &x:desc){
            if(isChild[x[0]]!=true){
                return createdNodes[x[0]];
            }
        }
        return NULL;
    }
};
int main()
{
    
    return 0;
}