// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing 
// a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. 
// If you cannot achieve any profit, return 0.
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices){
    int totalProfit=0;
    int n=prices.size();
    for(int i=0;i<prices.size();i++){
        int profit=0;
        int j=i;
        while(j+1<=n-1 && prices[j+1]>=prices[j]){
            j++;
        }
        profit=prices[j]-prices[i];
        if(profit>0)totalProfit+=profit;
        i=j;
    }
    return totalProfit;
}
int main()
{

    return 0;
}