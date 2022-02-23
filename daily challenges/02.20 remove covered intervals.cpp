#include<bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
int removeCoveredIntervals(vector<vector<int>>& arr) {
    int n=arr.size();
    int ans=n;
    for(int i=0;i<n;i++){
        int s2=arr[i][0];
        int e2=arr[i][1];
        for(int j=0;j<n;j++){
            if(i==j)continue;
            int s1=arr[j][0];
            int e1=arr[j][1];
            if(s2<=e1 && s2>=s1 && e2<=e1 && e2>=s2){
                ans--;
                break;
            }
        }
    }
    return ans;
}
};
*/
class Solution {
public:
int removeCoveredIntervals(vector<vector<int>>& arr) {
    sort(arr.begin(), arr.end());
    int n=arr.size();
    int left=-1, right=-1;
    int ans=0;
    for(int i=0;i<n;i++){
        int s=arr[i][0];
        int e=arr[i][1];
        if(s>=left && e<=right){
            ans++;
        }
        else{
            left=s;
            right=e;
        }
    }
    return n-ans;
}
};
int main()
{
    vector<vector<int>>arr{
        {1,4},
        {2,8},
        {2,6},
        {2,4},
        {2,2}
    };
    sort(arr.begin(), arr.end());
    for(auto it:arr){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    return 0;
}