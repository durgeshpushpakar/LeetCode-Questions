#include<bits/stdc++.h>
using namespace std;
int helper(int *arr, int s, int e, vector<vector<int>>&temp){
    if(e-s<=1)return 0;
    if(temp[s][e]!=-1)return temp[s][e];
    int ans=INT_MAX;
    for(int k=s+1;k<e;k++){
        int a=helper(arr, s, k, temp)+helper(arr, k, e, temp)+(arr[s]*arr[k]*arr[e]);
        ans=min(ans, a);
    }
    temp[s][e]=ans;
    return ans;
}
int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int>>temp(n+1, vector<int>(n+1, -1));
    return helper(arr, 0, n, temp);
}
int matrixChainMultiplication_DP(int* arr, int n) {
    vector<vector<int>>temp(n+1, vector<int>(n+1));
    // initialising some elements
    n++;
    for(int i=1;i<n;i++)temp[i][i]=0;

    for(int L=2;L<=n-1;L++){
        for(int i=1;i<=n-L;i++){
            int j=i+L-1;
            temp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int a=temp[i][k]+temp[k+1][j]+(arr[i-1]*arr[k]*arr[j]); 
                temp[j][k]=min(temp[j][k], a);
            }
        }
    }
    return temp[1][n-1];
}

int main()
{

    return 0;
}