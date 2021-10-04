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
void printLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*>visitedNodes;
    visitedNodes.push(root);
    while(!visitedNodes.empty()){
        TreeNode<int> *temp=visitedNodes.front();
        visitedNodes.pop();
        cout<<temp->data<<": ";
        for(int i=0;i<temp->children.size();i++){
            visitedNodes.push(temp->children[i]);
            cout<<temp->children[i]->data<<", ";
        }
        cout<<endl;
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
TreeNode<int>* takeInputLevelWise(){
    queue<TreeNode<int>*>q;
    int rootData;
    cout<<"Enter Data:"<<endl;
    cin>>rootData;
    TreeNode<int> *root=new TreeNode<int>(rootData);
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* temp=q.front();
        q.pop();
        cout<<"Enter num of children of "<<temp->data<<endl;
        int num;cin>>num;
        for(int i=0;i<num;i++){
            cout<<"Enter Data"<<endl;
            int data;cin>>data;
            TreeNode<int>*newNode=new TreeNode<int>(data);
            q.push(newNode);
            temp->children.push_back(newNode);
        }
    }
    return root;
}
int countNodes(TreeNode<int>* root){
    int ans=0;
    if(root==NULL)return 0;
    for(int i=0;i<root->children.size();i++){
        ans+=countNodes(root->children[i]);
    }
    return ans+1;
}
int getHeight(TreeNode<int>* root){
    if(root==NULL)return 0;
    int maxHeight=0;
    for(int i=0;i<root->children.size();i++){
        int smallHeight=getHeight(root->children[i]);
        maxHeight=(smallHeight>maxHeight)? smallHeight:maxHeight;
    }
    return maxHeight+1;
}
int main()
{
    TreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    cout<<countNodes(root);
    return 0;
}