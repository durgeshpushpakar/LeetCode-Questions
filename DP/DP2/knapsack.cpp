#include<bits/stdc++.h>
using namespace std;
// recursive
int knapsack(int *weights, int *values, int n, int maxWeight){
    if(n==0 ||maxWeight==0)return 0;
    if(weights[0]<=maxWeight){
        int a=knapsack(weights+1, values+1, n-1, maxWeight-weights[0])+values[0];
        int b=knapsack(weights+1, values+1, n-1, maxWeight);
        return max(a, b);
    }
    else return knapsack(weights+1, values+1, n-1, maxWeight);
}

// memoization
int helper(int *weights, int *values, int n, int maxWeight, vector<vector<int>>&arr){
    if(n==0||maxWeight==0)return 0;

    if(arr[n][maxWeight]!=-1)return arr[n][maxWeight];

    if(weights[0]>maxWeight){
        arr[n][maxWeight]= helper(weights+1, values+1, n-1, maxWeight, arr);
        return arr[n][maxWeight];
    }
    int a=helper(weights+1, values+1, n-1, maxWeight-weights[0], arr)+values[0];
    int b=helper(weights+1, values+1, n-1, maxWeight, arr);
    arr[n][maxWeight]=max(a, b);
    return arr[n][maxWeight];

}
int knapsack_mem(int *weights, int *values, int n, int maxWeight){
    vector<vector<int>>arr(n+1, vector<int>(maxWeight, -1));
    return helper(weights, values,n, maxWeight, arr);
}


int knapsack_DP(int *weights, int *values, int n, int maxWeight){
    vector<vector<int>>arr(n+1, vector<int>(maxWeight+1));
    
    // filling initial items 
    for(int i=0;i<=n;i++)arr[i][0]=0;
    for(int j=0;j<=maxWeight;j++)arr[0][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxWeight;j++){
            if(weights[n-i]>j)
                arr[i][j]=arr[i-1][j];
            else {
                arr[i][j]=max(arr[i-1][j], arr[i-1][j-weights[n-i]]+values[n-i]);
            }
        }
    }
    return arr[n][maxWeight];
}
int main()
{

    return 0;
}