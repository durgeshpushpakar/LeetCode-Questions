// https://leetcode.com/problems/majority-element-ii/
#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums) {
    int element=nums[0];
    int freq=1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==element){
            freq++;
        }
        else{
            freq--;
        }
        if(freq==0){
            element=nums[i];
            freq=1;
        }
    }        
    return element;
}
int main()
{

    return 0;
}