#include<bits/stdc++.h>
using namespace std;
// recursive solution
int editDistance(string s, string t) {
    int x=s.length();
    int y=t.length();
    if(y==0 && x==0)return 0;
    if(x==0)return y;
    if(y==0)return x;

    // recursive calls
    if(s[0]==t[0])return editDistance(s.substr(1), t.substr(1));
    // insert
    int ans1=editDistance(s, t.substr(1));
    // delete
    int ans2=editDistance(s.substr(1), t);
    // replace
    int ans3=editDistance(s.substr(1), t.substr(1));
    return 1+min(ans1,min(ans2, ans3));
}

//memoization
int helper(string s, string t, vector<vector<int>>&arr){
    int x=s.length();
    int y=t.length();
    //base case
    if(y==0 && x==0)return 0;
    if(x==0)return y;
    if(y==0)return x;
    if(arr[x][y]!=-1)return arr[x][y];
    // recursive calls
    if(s[0]==t[0])return helper(s.substr(1), t.substr(1), arr);
    // insert
    int ans1=helper(s, t.substr(1), arr);
    // delete
    int ans2=helper(s.substr(1), t, arr);
    // replace
    int ans3=helper(s.substr(1), t.substr(1), arr);
    arr[x][y]=1+min(ans1,min(ans2, ans3));
    return arr[x][y];
}
int editDistance_mem(string s, string t) {
    vector<vector<int>>arr(s.length()+1, vector<int>(t.length()+1, -1));
    return helper(s, t, arr);
}


//DP
int editDistance_DP(string s, string t){
    int x=s.length();
    int y=t.length();
    vector<vector<int>>arr(x+1, vector<int>(y+1));

    //filling initial values
    arr[0][0]=0;
    for(int i=1;i<=x;i++)arr[i][0]=i;
    for(int j=1;j<=y;j++)arr[0][j]=j;

    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(s[x-i]==t[y-j])arr[i][j]=arr[i-1][j-1];
            else {
                arr[i][j]=1+min(arr[i-1][j], min(arr[i][j-1], arr[i-1][j-1]));
            }
        }
    }
    return arr[x][y];
}
int main()
{

    return 0;
}