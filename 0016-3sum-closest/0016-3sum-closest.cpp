class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int minDiff=INT_MAX;
        sort(nums.begin(), nums.end());
        int ans=INT_MAX;
        for(int k=n-1;k>=2;k--){
            int i=0, j=k-1, temp=target-nums[k];
            while(i<j){
                if(minDiff>abs(temp-nums[i]-nums[j])){
                    minDiff=abs(temp-nums[i]-nums[j]);
                    ans=nums[i]+nums[j]+nums[k];
                }
                if(nums[i]+nums[j]>=temp){
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};