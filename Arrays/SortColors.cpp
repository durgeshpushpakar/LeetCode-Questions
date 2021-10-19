#include<bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& nums) {
    int size=nums.size();
    int i=0;
    while(size--){
        if(nums[i]==0){
            nums.erase(nums.begin()+i);
            nums.insert(nums.begin(), 0);
        }      
        else if(nums[i]==2){
            nums.erase(nums.begin()+i);
            nums.push_back(2);
            continue;
        }
        i++;
    }
}
int main()
{

    return 0;
}