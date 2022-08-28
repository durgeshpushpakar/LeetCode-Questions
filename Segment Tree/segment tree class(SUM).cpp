#include<bits/stdc++.h>
using namespace std;
// sum segment tree
class SegmentTree{
    public:
    vector<int>arr, tree;
    int n;
    SegmentTree(vector<int>&temp, int n):arr(n), tree(4*n){
        arr=temp;
        this->n=n;
        buildTree();
    }
    void buildHelper(int left, int right, int idx){
        if(left>right)return;
        if(left==right){
            tree[idx]=arr[left];
            return;
        }
        int mid=(left+right)/2;
        buildHelper(left, mid, 2*idx+1);
        buildHelper(mid+1, right, 2*idx+2);
        tree[idx]=tree[2*idx+1]+tree[2*idx+2];
    }
    void updateHelper(int left, int right, int idx, int index, int val){
        if(left>right)return;
        if(left==right){
            tree[idx]=val;
            return;
        }
        int mid=(left+right)/2;
        if(index>=left && index<=mid)updateHelper(left, mid, 2*idx+1, index, val);
        else if(index>=mid+1 && index<=right)updateHelper(mid+1, right, 2*idx+2, index, val);
        tree[idx]=tree[2*idx+1]+tree[2*idx+2];
    }
    int queryHelper(int left, int right, int idx, int l, int r){
        if(right<l || left>r)return 0;
        if(left==right){
            if(left>=l && right<=r)return tree[idx];
            return 0;
        }
        if(left>=l && right<=r)return tree[idx];
        int mid=(left+right)/2;
        return queryHelper(left, mid, 2*idx+1, l, r) + queryHelper(mid+1, right, 2*idx+2, l, r);
    }
    void buildTree(){
        buildHelper(0, n-1, 0);
    }
    void update(int index, int val){
        updateHelper(0, n-1, 0, index, val);
    }
    int query(int l, int r){
        return queryHelper(0, n-1, 0, l, r);
    }
};
class NumArray {
public:
    SegmentTree T;
    NumArray(vector<int>& nums):T(nums, nums.size()) {

    }
    
    void update(int index, int val) {
        T.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return T.query(left, right);
        // return 0;
    }
};


int main()
{
    
    return 0;
}