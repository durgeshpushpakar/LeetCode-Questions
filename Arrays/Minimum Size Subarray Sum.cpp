#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int minSubArrayLen(int target, vector<int>& arr) {
    vector<int>prefix(arr.size());
    int n=arr.size();
    prefix[0]=arr[0];
    int minLength=INT_MAX;
    for(int i=0;i<n;i++){
        if(i!=0)prefix[i]=arr[i]+prefix[i-1];
        for(int j=i;j>=0;j--){
            int sum;
            if(j==i)sum=arr[i];
            else if(j==0)sum=prefix[i];
            else sum=prefix[i]-prefix[j-1];
            if(sum>=target && i-j+1<minLength)minLength=i-j+1;
        }
    }
    if(minLength==INT_MAX)return 0;
    return minLength;
}
int minSubArrayLen2(int target, vector<int>& arr) {
    int left=0;
    int n=arr.size();
    int sum=0;
    int minLength=INT_MAX;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        while(sum>=target){
            if(i-left+1<minLength){
                minLength=i-left+1;
            }
            sum-=arr[left];
            left++;
        }        
    }
    if(minLength==INT_MAX)minLength=0;
    return minLength;
}
};
int main()
{

    return 0;
}