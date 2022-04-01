#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int gcd(int a, int b){
    return (b==0)? a : gcd(b, a%b);
}
vector<int> replaceNonCoprimes(vector<int>& arr) {
    vector<int>ans;
    int n=arr.size();
    ans.push_back(arr[0]);
    if(n==1)return ans;

    for(int i=1;i<n;i++){
        int curr=arr[i];
        if(gcd(curr, ans.back())==1){
            ans.push_back(curr);
            continue;
        }
        
        while(!ans.empty() && gcd(curr, ans.back())!=1){
            int lcm=curr*ans.back()/gcd(curr, ans.back());
            ans.pop_back();
            curr=lcm;
        }
        ans.push_back(curr);
    }
    return ans;
}
};
int main()
{
    
    return 0;
}