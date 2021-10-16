#include<bits/stdc++.h>
using namespace std;
// Kadane Algorithm
#define mod 998244353

int f(int nums[], int start, int end){
    bool is_negative=true;
    int max_negative=INT_MIN;
    for(int i=start;i<=end;i++){
        max_negative=max(max_negative, nums[i]);
        if(nums[i]>=0){
            is_negative=false;
            break;
        }        
    }
    if(is_negative)return max_negative;
    int maxSum=0;
    int maxTillNow=0;
    for(int i=start;i<=end;i++){
        long int temp=maxTillNow+nums[i];
        temp=temp%mod;
        maxTillNow=temp;
        if(maxTillNow<0)maxTillNow=0;
        if(maxTillNow>maxSum)maxSum=maxTillNow;
    }
    return maxSum;
}
int g(int arr[], int i, int j, int n){
    i--;
    j--;
    long int temp1=f(arr, 1, i-1)%mod;
    long int temp2=f(arr ,j+1, n)%mod;
    return max(temp1, temp2);
}
int* max_sum_array(int A[], int N, int queries[], int Q){
    int ans[Q];
    int ansIndex=0;
    for(int i=0;i<Q;i++){
        int L=queries[i];
        L--;
        int sum=0;
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                long int temp=g(A, j, k, N)%mod;
                long int temp1=(sum+temp)%mod;
                sum+=temp1;
            }
        }
        ans[ansIndex]=sum;
        ansIndex++;
    }
    return ans;
}
int main(){
    int arr[2]={2,4};

    cout<<g(arr,1,1,2);
    return 0;
}