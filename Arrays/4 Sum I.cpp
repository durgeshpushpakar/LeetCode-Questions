#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n=nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>>ans;
    map <vector<int>, int> map;
    for(int i=0;i<=n-4;i++){
        if(i>0 && nums[i]==nums[i-1])continue;
        for(int j=i+1;j<=n-3;j++){
            if(j>i+1 && nums[j]==nums[j-1])continue;
            int reqSum = target-(nums[i]+nums[j]);
            int low=j+1, high=n-1;
            while(low<high){
                if(nums[low]+nums[high]==reqSum){
                    vector<int>temp{nums[i], nums[j], nums[low], nums[high]};
                    ans.push_back(temp);
                    while(low<high && nums[low]==nums[low+1])low++;
                    while(high>low && nums[high]==nums[high-1])high--;
                    low++;     
                    high--;                
                }
                else if(nums[low]+nums[high]<reqSum)low++;
                else high--;
            }            
        }
    } 
    return ans;   
}
};
int main()
{

    return 0;
}