#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
int countLeafNodes(TreeNode<int>* root){
    if(root==NULL)return 0;
    if(root->children.size()==0)return 1;
    int totalLeaf=0;
    for(int i=0;i<root->children.size();i++){
        totalLeaf+=countLeafNodes(root->children[i]);
    }
    return totalLeaf;
}
int main(){

    return 0;
}