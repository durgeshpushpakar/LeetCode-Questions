#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    if(nums.size()==0)return 0;
    int newSize=1;
    int i=0,j=0;
    for(i=0; i<nums.size();i++){
        if(nums[i]!=nums[j]){
            nums[newSize++]=nums[i];
            j=i;
        }
    }
    return newSize;
}
int main(){

    return 0;
}