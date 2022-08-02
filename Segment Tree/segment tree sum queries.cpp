#include<bits/stdc++.h>
using namespace std;
class NumArray {
public:
    int n;
    vector<int>arr;vector<int>tree;
    int helper(int low, int high, int idx, int l, int r){
        if(low>=l && high<=r)return tree[idx];
        else if(l>high || r<low){
            return 0;
        } 
        int mid=(low+high)/2;
        return helper(low, mid, 2*idx+1, l, r)+helper(mid+1, high, 2*idx+2, l, r);
    }
    // maximum query segment tree
    void buildTree(int low, int high, int ind){
        if(low==high){
            tree[ind]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        buildTree(low, mid, (2*ind)+1);
        buildTree(mid+1, high, (2*ind)+2);
        // segment tree for the maximum in a range
        tree[ind]=tree[2*ind+1]+tree[2*ind+2];
    }
    void updateHelper(int idx, int low, int high, int index, int value){
        if(low==high){
            if(index==low){
                arr[low]=value;
                tree[idx]=value;
            }
            return;
        }
        if(index<low || index>high)return;
        int mid=(low+high)/2;
        updateHelper(2*idx+1, low, mid, index, value);
        updateHelper(2*idx+2, mid+1, high, index, value);
        tree[idx]=tree[2*idx+1]+tree[2*idx+2];
    }
    NumArray(vector<int>& nums) {
        arr=nums;
        n=nums.size();
        tree.resize(4*n);
        buildTree(0, n-1, 0);
    }
    
    void update(int index, int val) {
        updateHelper(0, 0, n-1, index, val);
    }
    
    int sumRange(int l, int r) {
        return helper(0, n-1, 0, l, r);
    }
};