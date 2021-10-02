#include<bits/stdc++.h>
#include "Treenode.h"
using namespace std;
void printTree(TreeNode<int>*root){
    if(root==NULL)return;
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);
    cout<<"enter num of children of "<<rootData<<endl;
    int num;cin>>num;
    for(int i=0;i<num;i++){
        TreeNode<int> *temp=takeInput();
        root->children.push_back(temp);
    }
    return root;
}
// TreeNode<int>* takeInputLevelOrder()
int main()
{
    TreeNode<int>* root=takeInput();
    printTree(root);
    return 0;
}