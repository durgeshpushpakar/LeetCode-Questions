// longest common subsequence
#include<bits/stdc++.h>
using namespace std;
// recursive
int LCS(string s, string t){
    if(s.length()==0 || t.length()==0){
        return 0;
    }
    if(s[0]==t[0]){
        int smallAns2=LCS(s.substr(1), t.substr(1));
        return smallAns2+1;
    }
    int smallAns1=LCS(s.substr(1), t);
    int smallAns2=LCS(s.substr(1), t.substr(1));
    int smallAns3=LCS(s, t.substr(1));
    return max(smallAns1, max(smallAns2, smallAns3));
}

//memoization
int helper(string s, string t, vector<vector<int>>&arr){
    int x=s.length();   
    int y=t.length();
    if(x==0 || y==0){
        return 0;
    }
    if(s[0]==t[0]){
        int smallAns2=helper(s.substr(1), t.substr(1),arr);
        arr[x][y]=smallAns2+1;
        return arr[x][y];
    }
    int smallAns1=helper(s.substr(1), t, arr);
    int smallAns2=helper(s.substr(1), t.substr(1), arr);
    int smallAns3=helper(s, t.substr(1), arr);
    arr[x][y]=max(smallAns1, max(smallAns2, smallAns3));
    return arr[x][y];
}
int LCS_mem(string s, string t){
    string ans="";
    vector<vector<int>>arr(s.length()+1, vector<int>(t.length()+1, -1));
    return helper(s, t, arr);
}


int LCS_DP(string s, string t){
    int y=t.length();
    int x=s.length();
    vector<vector<int>>arr(s.length()+1, vector<int>(t.length()+1));
    // filling initial easy row and column
    for(int i=0;i<=y;i++)arr[0][i]=0;
    for(int i=0;i<=x;i++)arr[i][0]=0;

    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(s[x-i]==t[y-j]){
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else{
                arr[i][j]=max(max(arr[i-1][j], arr[i][j-1]), arr[i-1][j-1]);
            }
        }
    }
    return arr[x][y];
}
int main(){
    string s="abcdd";
    string t="badcadd";
    cout<<LCS_DP(s, t);
    return 0;
}