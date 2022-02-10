#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int removeDuplicates(vector<int>& nums) {
    int in=2;
    int n=nums.size();
    for(int i=2;i<n;i++){
        if(nums[in-2]!=nums[i]){
            nums[in]=nums[i];
            in++;
        }
    }
    return in;
}
};
int main()
{

    return 0;
}