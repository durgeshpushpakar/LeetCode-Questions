#include<bits/stdc++.h>
using namespace std;
vector <int> preorder(Node* root)
{
    Node*cur=root;
    vector<int>ans;
    while(cur){
        if(cur->left){
            Node*temp=cur->left;
            while(temp->right && temp->right!=cur)temp=temp->right;
            if(!temp->right){
                temp->right=cur;
                ans.push_back(cur->data);
                cur=cur->left;
            }
            else if(temp->right==cur){
                temp->right=NULL;
                cur=cur->right;
            }
        }
        else {
            ans.push_back(cur->data);
            cur=cur->right;
        }
    }
    return ans;
}