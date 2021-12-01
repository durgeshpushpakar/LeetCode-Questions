#include<bits/stdc++.h>
using namespace std;

int helper(int **arr, int i, int j, int m, int n){
    if(i==m && j==n)return arr[m][n];
    if(i>m || j>n)return INT_MAX;
    int x=helper(arr, i+1, j, m, n);
    int y=helper(arr, i, j+1, m, n);
    int z=helper(arr, i+1, j+1, m, n);
    return min(min(x, y), z) + arr[i][j];
}
int minCostPath(int **input, int m, int n){
    return helper(input, 0, 0, m-1, n-1);
}
// memoization
int helper(int **arr, int i, int j, int m, int n, vector<vector<int>>&temp){
    if(i>m || j>n)return INT_MAX;
    if(temp[i][j]!=-1)return temp[i][j];
    int x=helper(arr, i+1, j, m, n, temp);
    int y=helper(arr, i, j+1, m, n, temp);
    int z=helper(arr, i+1, j+1, m, n, temp);
    temp[i][j]= min(min(x, y), z) + arr[i][j];
    return temp[i][j];
}
int minCostPath_mem(int **input, int m, int n){
    vector<vector<int>>arr(m, vector<int>(n, -1));
    arr[m-1][n-1]=input[m-1][n-1];
    return helper(input, 0, 0, m-1, n-1, arr);
}
int minCostPathDP(int **input, int m, int n){
    vector<vector<int>>output(m, vector<int>(n));
    output[m-1][n-1]=input[m-1][n-1];
    // fill last row
    for(int j=n-2;j>=0;j--)
        output[m-1][j]=output[m-1][j+1]+input[m-1][j];
    // fill last column
    for(int i=m-2;i>=0;i--)
        output[i][n-1]=input[i][n-1]+output[i+1][n-1];
    // filling other cells
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            output[i][j]=input[i][j]+min(min(output[i+1][j], output[i][j+1]), output[i+1][j+1]);
        }
    }
    return output[0][0];
}