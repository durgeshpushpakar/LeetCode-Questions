#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
class Solution {
public:
vector<long long>maxAns;
void helper(long long sum, unordered_set<long long>&uset, vector<long long>&ans){
    if(sum==0 && ans.size()>maxAns.size()){
        maxAns=ans;
        return;
    }
    for(long long i=1;i<sum;i++){
        if(uset.count(i)==0){
            uset.insert(i);
            ans.push_back(i);
            helper(sum-i, uset, ans);
            uset.erase(i);
            ans.pop_back();
        }
    }
    return;
}
vector<long long> maximumEvenSplit(long long finalSum) {
    if(finalSum%2==1)return {};
    unordered_set<long long>uSet;
    vector<long long>ans;
    helper(finalSum/2, uSet, ans);
    return maxAns;
}
};*/

class Solution {
public:
    vector<long long>maxAns;
    void helper(long long sum, unordered_set<long long>&uset){
        if(sum==0){
            if(uset.size()>maxAns.size()){
                maxAns.clear();
                for(auto itr=uset.begin();itr!=uset.end();itr++){
                    maxAns.push_back(2*(*itr));
                }
                return;
            }
            return;
        }
        for(int i=1;i<=sum;i++){
            if(uset.count(i)==0){
                uset.insert(i);
                helper(sum-i, uset);
                uset.erase(i);
            }
            else continue;
        }
    }
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2!=0)return maxAns;
        unordered_set<long long>uset;
        helper(finalSum/2, uset);   
        return maxAns;   
    }
};
int main()
{
    Solution S;
    vector<long long>ans=S.maximumEvenSplit(28);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}