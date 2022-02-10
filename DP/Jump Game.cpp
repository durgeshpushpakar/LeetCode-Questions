#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n, false);
    dp[0] = true;
    dp[1] = (nums[0] != 0) ? true : false;
    for (int i = 2; i < n; i++){
        for (int j = i - 1; j >= 0; j--){
            if(dp[j] && nums[j]>=i-j){
                dp[i]=true;
                break;
            }
        }
    }
    return dp[n-1];
}
};
int main()
{

    return 0;
}