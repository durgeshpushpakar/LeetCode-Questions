// https://leetcode.com/problems/merge-sorted-array/
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(n==0)return;
    if(m==0){
        nums1=nums2;
        nums1.resize(n);
        return;
    }
    int i=0, j=0;
    while(j<n){
        if(nums2[j]<=nums1[i]){
            nums1.insert(nums1.begin()+i, nums2[j]);
            i++;
            j++;
        }
        else{
            if(i==m+j-1){
                nums1.insert(nums1.begin()+i+1, nums2[j]);
                i++;j++;
            }
            else i++;
        }
    }
    nums1.resize(m+n);        
}
int main()
{
    return 0;
}