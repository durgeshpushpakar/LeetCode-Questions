// https://leetcode.com/contest/biweekly-contest-61/problems/find-original-array-from-doubled-array/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> findOriginalArray(vector<int>& changed) {
    vector<int>ans;
    vector<int>freq(100001, 0);
    for(int i=0;i<changed.size();i++)freq[changed[i]]++;
    if(freq[0]%2!=0)return ans;
    else if(freq[0]!=0 && freq[0]%2==0){
        ans.insert(ans.end(), freq[0]/2, 0);
    }
    for(int i=1;i<freq.size();i++){
        if(freq[i]<=0)continue;
        if(2*i<100001&&freq[i]<=freq[2*i]){
            ans.insert(ans.end(), freq[i], i);
            freq[2*i]-=freq[i];
            freq[i]=0;
        }
        else{
            ans.clear();
            return ans;
        }
    }
    return ans;
}
};
int main()
{

    return 0;
}