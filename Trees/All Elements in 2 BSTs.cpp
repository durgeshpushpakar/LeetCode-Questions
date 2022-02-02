#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// []
// [5,1,7,0,2]
class Solution {
public:
    void inOrder(TreeNode *root, vector<int> &arr){
        if(root==NULL)return;
        inOrder(root->left, arr);
        arr.push_back(root->val);
        inOrder(root->right, arr);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2, ans;
        inOrder(root1, arr1);
        inOrder(root2, arr2);
        for(auto itr:arr1)cout<<itr<<" ";
        cout<<endl;
        for(auto itr:arr2)cout<<itr<<" ";
        int i=0, j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<=arr2[j]){
                ans.push_back(arr1[i++]);
            }
            else ans.push_back(arr2[j++]);
        }
        while(i<arr1.size())ans.push_back(arr1[i++]);
        while(j<arr2.size())ans.push_back(arr2[j++]);
        return ans;
    }
};
vector<int> mergeArrays(){
    vector<int>arr1, ans;
    vector<int>arr2{1,2,3,4,5};
    int i=0, j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<=arr2[j])ans.push_back(arr1[i++]);
        else ans.push_back(arr2[j++]);
    }
    while(i<arr1.size())ans.push_back(arr1[i++]);
    while(j<arr2.size())ans.push_back(arr2[j++]);
    return ans;
}
int main()
{
    vector<int>ans=mergeArrays();
    for(auto itr:ans)cout<<itr<<" ";
    return 0;
}