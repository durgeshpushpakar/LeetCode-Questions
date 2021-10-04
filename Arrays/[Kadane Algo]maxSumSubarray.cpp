#include<bits/stdc++.h>
using namespace std;
// Kadane Algorithm
int maxSubArray(vector<int>& nums) {
    //check for all negatives
    bool is_negative=true;
    int max_negative=INT_MIN;
    for(int i=0;i<nums.size();i++){
        max_negative=max(max_negative, nums[i]);
        if(nums[i]>=0){
            is_negative=false;
            break;
        }        
    }
    if(is_negative)return max_negative;
    int maxSum=0;
    int maxTillNow=0;
    for(int i=0;i<nums.size();i++){
        maxTillNow+=nums[i];
        if(maxTillNow<0)maxTillNow=0;
        if(maxTillNow>maxSum)maxSum=maxTillNow;
    }
    return maxSum;
}
int main(){

    return 0;
}