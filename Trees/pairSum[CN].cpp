// https://classroom.codingninjas.com/app/classroom/me/5130/content/66471/offering/727006/problem/104
#include<bits/stdc++.h>
#include "TreeNode.h"
template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode*left;
    BinaryTreeNode*right;
    BinaryTreeNode(T val){
        data=val;
        left=right=NULL;
    }
};
void preOrderTraversal(BinaryTreeNode<int>*root, vector<int>&ans){
    if(root==NULL)return;
    ans.push_back(root->data);
    preOrderTraversal(root->left, ans);
    preOrderTraversal(root->right, ans);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    vector<int>ans;
    preOrderTraversal(root, ans);
    unordered_map<int, int>freq;
    for(int i=0;i<ans.size();i++){
        if(freq.count(sum-ans[i])==1){
            cout<<ans[i]<<" "<<sum-ans[i]<<endl;
        }
        freq[ans[i]]++;
    }
}
using namespace std;
int main()
{

    return 0;
}