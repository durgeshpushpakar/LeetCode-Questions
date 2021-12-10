// https://leetcode.com/contest/weekly-contest-270/problems/finding-3-digit-even-numbers/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> findEvenNumbers(vector<int>& a) {
int n=a.size();
set<int>ans;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i==j)continue;
        for(int k=0;k<n;k++){
            if(i==k || j==k)continue;
            if(a[i]!=0 && a[k]%2==0)
                ans.insert(100*a[i]+10*a[j]+a[k]);
        }
        if(a[i]==0)break;
    }
}
return vector<int>(ans.begin(), ans.end());
}
};
int main()
{

    return 0;
}