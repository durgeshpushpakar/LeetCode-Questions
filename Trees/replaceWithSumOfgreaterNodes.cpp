#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode {
    public: 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int helper(BinaryTreeNode<int>* root, int sum){
    if(root==NULL)return sum;
    int right=helper(root->right, sum);
    root->data+=right;
    int left=helper(root->left, root->data);
    return left;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    int x=helper(root, 0);
}
/*
VOID solution
void helper(BinaryTreeNode<int>* root, int &sum){
    if(root==NULL)return;
    helper(root->right, sum);
    sum+=root->data;
    root->data=sum;
    helper(root->left, sum);
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    int sum=0;
     helper(root, sum);
}
*/
int main()
{

    return 0;
}