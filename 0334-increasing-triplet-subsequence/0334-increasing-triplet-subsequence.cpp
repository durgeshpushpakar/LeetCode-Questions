class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n, INT_MIN), right(n, INT_MIN);
        int leftMin=nums[0];
        for(int i=1;i<n;i++){
            if(leftMin<nums[i])left[i]=leftMin;
            leftMin=min(leftMin, nums[i]);
        }
        int rightMax=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(rightMax>nums[i])right[i]=rightMax;
            rightMax=max(rightMax, nums[i]);
        }
        for(int i=1;i<n-1;i++){
            if(left[i]!=INT_MIN && right[i]!=INT_MIN)return true;
        }
        return false;
    }
};