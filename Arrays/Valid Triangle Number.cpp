// https://leetcode.com/problems/valid-triangle-number/
// explanation--> https://leetcode.com/problems/valid-triangle-number/discuss/128135/A-similar-O(n2)-solution-to-3-Sum
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int triangleNumber(vector<int>& arr) {
    int ans=0;
    int n=arr.size();
    sort(arr.begin(), arr.end());
    for(int i=n-1;i>=2;i--){
        int j=0, k=i-1;
        while(j<k){
            if(arr[j]+arr[k]>arr[i]){
                ans+=k-j;
                k--;
            }
            else{
                j++;
            }
        }
    }
    return ans;
}
};
int main()
{

    return 0;
}