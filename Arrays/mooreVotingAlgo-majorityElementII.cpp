#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
    int c1=0, c2=0;
    int num1=-1, num2=-1;
    for(int i=0;i<nums.size();i++){
        if(num1==nums[i])c1++;
        else if(num2==nums[i])c2++;
        else if(c1==0){
            num1=nums[i];
            c1=1;
        }
        else if(c2==0){
            num2=nums[i];
            c2=1;
        }
        else {
            c1--;
            c2--;
        }
    }
}
int main()
{

    return 0;
}