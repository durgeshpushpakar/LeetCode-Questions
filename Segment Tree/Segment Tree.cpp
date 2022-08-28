#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>arr(n);vector<int>tree(4*n);
// query helper
int helper(int low, int high, int ind, int l, int r){
    if(low>=l && high<=r)return tree[ind];
    else if(l>high || r<low){
        return INT_MIN;
    } 
    int mid=(low+high)/2;
    return max(helper(low, mid, 2*idx+1, l, r), helper(mid+1, high, 2*idx+2, l, r));
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
    tree[ind]=max(tree[2*ind+1], tree[2*idx+2]);
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
    tree[idx]=max(tree[2*idx+1], tree[2*idx+2]);
}
void update(int index, int value){
    return updateHelper(0, 0, n-1, index, value);
}
int query(int l, int r){
    return helper(0, n-1, 0, l, r);
}
int main()
{
    
    buildTree(arr, tree, 0, n-1, 0); 
    return 0;
}