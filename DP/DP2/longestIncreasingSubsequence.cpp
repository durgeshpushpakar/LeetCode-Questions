#include<bits/stdc++.h>
using namespace std;
// int helper(int* arr, int n, int lastElement) {
//     if(n<=0)return 0;
//     if(arr[0]<=lastElement){
//         return helper(arr+1, n-1, lastElement);
//     }
//     int a=helper(arr+1, n-1, lastElement);
//     int b=helper(arr+1, n-1, arr[0])+1;
//     return max(a, b);
// }
// int longestIncreasingSubsequence(int *arr, int n){
//     return helper(arr, n, INT_MIN);
// }


// best solution
int longestIncreasingSubsequence(int *arr, int n){
    vector<int>output(n);
    output[0]=1;
    for(int i=1;i<n;i++){
        int ans=1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                ans=max(ans, output[j]+1);
            }
        }
        output[i]=ans;
    }
    int ans=0;
    for(int i=0;i<n;i++)ans=max(ans, output[i]);
    return ans;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}