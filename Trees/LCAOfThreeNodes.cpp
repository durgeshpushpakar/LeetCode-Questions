// https://www.codingninjas.com/codestudio/problems/lca-of-three-nodes_794944
#include<bits/stdc++.h>
using namespace std;
template <typename T>
    class BinaryTreeNode {
    public :
	    T data;
	    BinaryTreeNode<T> *left;
	    BinaryTreeNode<T> *right;

	    BinaryTreeNode(T data) {
	        this -> data = data;
	        left = NULL;
	        right = NULL;
	    }
    };
BinaryTreeNode<int>*lca(BinaryTreeNode<int>*root, int node1, int node2){
    if(root==NULL || root->data==node1 || root->data==node2)return root;
    BinaryTreeNode<int>*leftAns=lca(root->left, node1, node2);
    BinaryTreeNode<int>*rightAns=lca(root->right, node1, node2);
    if(leftAns!=NULL && rightAns!=NULL)return root;
    if(leftAns)return leftAns;
    return rightAns;
}
BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
	return lca(root, node1, lca(root, node2, node3)->data);
}