#include<bits/stdc++.h>
using namespace std;
/*
FAILED
arr[]={3,1,3,2,4,3}

*/
class Solution {
public:
int minimumOperations(vector<int>& nums) {
    int n=nums.size();
    if(nums.size()<=2)return 0;
    bool allEqual=true;
    for(int i=1;i<n;i++){
        if(nums[i]!=nums[0]){
            allEqual=false;
            break;
        }
    }
    if(allEqual)return n/2;
    int ans1=0, ans2=0;
    int num1=nums[0];    
    int num2=nums[1];
    vector<int>arr1=nums;
    vector<int>arr2=nums;
    for(int i=2;i<n;i++){
        if(i%2==0 && arr1[i]!=num1){
            arr1[i]=num1;
            ans1++;
        }
        else if(i%2!=0 && arr1[i]!=num2){
            arr1[i]=num2;
            ans1++;
        }
    }   
    if(arr1[0]==arr1[1])ans1=n/2; 
    num1=nums[n-1];
    num2=nums[n-2];
    bool isnum1=true;
    for(int i=n-3;i>=0;i--){
        if(isnum1 && nums[i]!=num1){
            arr2[i]=num1;
            ans2++;
        }
        else if(!isnum1 && nums[i]!=num2){
            arr2[i]=num2;
            ans2++;
        }
        isnum1=!isnum1;
    }
    if(arr2[0]==arr2[1])ans2=n/2;
    
    return min(ans1, ans2);
}
};
int main()
{

    return 0;
}