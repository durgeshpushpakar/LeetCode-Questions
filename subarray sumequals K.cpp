#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int>makePrefix(vector<int>& arr){
    vector<int>ans;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        ans.push_back(sum);
    }
    return ans;
}
int subarraySum(vector<int>& nums, int k) {
    vector<int>prefix=makePrefix(nums);   
    unordered_map<int, int>map;   
    int ans=0;
    for(int i=0;i<prefix.size();i++){
        if(prefix[i]==k){
            ans++;
        }
        if(map.count(prefix[i]-k)){
            ans+=map[prefix[i]-k];
        }
        map[prefix[i]]++;
    }
    return ans;
}
};
int main()
{

    return 0;
}