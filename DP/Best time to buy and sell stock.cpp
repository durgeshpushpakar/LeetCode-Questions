#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int maxProfit(vector<int>& arr) {
    if(arr.size()==1)return 0;
    int minTillNow=arr[0];
    int maxProfit=0;
    for(int i=1;i<arr.size();i++){
        int profit = arr[i] - minTillNow;
        maxProfit=max(maxProfit, profit);
        minTillNow=min(minTillNow, arr[i]);
    }
    return maxProfit;
}
};
int main()
{

    return 0;
}