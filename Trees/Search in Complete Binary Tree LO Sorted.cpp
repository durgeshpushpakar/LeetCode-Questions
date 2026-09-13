/*
### Search in a Sorted Complete Binary Tree

**Problem Statement**
Given a complete binary tree where the nodes are filled in level-order and the values are sorted according to their level-order traversal. Specifically, for any two nodes `u` and `v`, if `u` appears before `v` in the level-order traversal, then val(u) <= val(v).

You are provided with the `root` of the tree and the total number of nodes `N`. Implement an efficient algorithm to determine if a specific `target` value exists in the tree.

Your solution should aim for a time complexity better than `O(N)` by leveraging the structural properties of a complete binary tree.

**Input Format**
* The `root` of a complete binary tree.
* An integer `N` representing the total number of nodes.
* A `target` value to search for.

**Output Format**
* Returns boolean `true` if the target exists, and `false` otherwise.

**Constraints**
* 1 <= N <= 10^9
* The tree is guaranteed to be a valid complete binary tree.
*/

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int noOfBits(int n){
        int ans=0;
        while(n){
            n>>=1;
            ans++;
        }
        return ans;
    }
    bool searchInCompleteBinaryTree(TreeNode* root, int n, int target) {
        // TODO: Implement O((log N)^2) binary search approach
        int low=1, high=n;
        int mid=((high-low)/2)+low;
        while(low<=high){
            int mid=((high-low)/2)+low;
            int width=noOfBits(mid);
            int mask= (width>1)?1<<(width-2) : 0;
            int nodeVal=iterate(root, mid, mask);
            if(nodeVal==target)return true;
            else if(nodeVal>target)high=mid-1;
            else low=mid+1;
        }
        return false;
    }
    int iterate(TreeNode*root, int mid, int mask){
        TreeNode*temp=root;
        while(mask){
            if(mid & mask){
                temp=temp->right;
            }
            else temp=temp->left;
            mask=mask>>1;
        }
        return temp->val;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    // Example test setup can be added here

    return 0;
}
