#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
int maxProfit(vector<int>& prices) {
    int j=0;
    int sum=0;
    int Profit=0;
    for(int i=0;i<prices.size();i++){
        int prof=prices[i]-prices[j];
        if(prof>Profit){
            Profit=prof;
        }
        else if(prof<Profit){
            j=i;
            sum+=Profit;
            Profit=0;
        }
    }
    sum+=Profit;
    return sum;
}
vector<vector<int> > stockBuySell(vector<int> arr, int n){
    vector<vector<int>>ans;
    int i=0;
    while(i<=n-1){
        while(i<n-1 && arr[i+1]<=arr[i])i++;
        if(i==n-1)break;
        int temp1=i++;
        while(arr[i]>=arr[i-1])i++;
        ans.push_back({temp1, i-1});
    }
    return ans;
}
int main(){

    return 0;
}