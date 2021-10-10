// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing 
// a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. 
// If you cannot achieve any profit, return 0.
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices){
    int maxProfit=INT_MIN;
    int len=prices.size();
    int minTillNow=INT_MAX;
    for(int i=0;i<len;i++){
        if(prices[i]<minTillNow)minTillNow=prices[i];
        int profit=prices[i]-minTillNow;
        maxProfit=max(profit, maxProfit);
    }
    return maxProfit;
}
int main()
{

    return 0;
}