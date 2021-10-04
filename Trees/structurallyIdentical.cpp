#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1==NULL && root2==NULL)return true;
    if(root1==NULL || root2==NULL)return false;
    if(root1->data==root2->data && root1->children.size()==root2->children.size()){
        for(int i=0;i<root1->children.size();i++){
            bool temp=areIdentical(root1->children[i], root2->children[i]);
            if(temp==false)return false;
        }
        return true;
    }
    else return false;
}