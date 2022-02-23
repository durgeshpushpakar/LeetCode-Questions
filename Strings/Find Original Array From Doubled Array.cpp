// https://leetcode.com/contest/biweekly-contest-61/problems/find-original-array-from-doubled-array/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> findOriginalArray(vector<int>& arr) {
    vector<int>map(100001, 0);
    vector<int>ans;
    int n=arr.size();
    for(int i=0;i<n;i++){
        map[arr[i]]++;
    }   
    if(map[0]%2==1)return ans;
    else if(map[0]!=0){
        ans.insert(ans.end(), map[0]/2, 0);
    }
    for(int i=1;i<map.size();i++){
        if(map[i]==0)continue;
        int temp=i*2;
        if(map[temp]>=map[i]){
            ans.insert(ans.end(), map[i], i);
            map[temp]-=map[i];
            map[i]=0;
        }
        else{
            return {};
        }
    }
    return ans;
}
};
int main()
{

    return 0;
}