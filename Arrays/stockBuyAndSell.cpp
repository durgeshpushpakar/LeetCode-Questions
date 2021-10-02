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
int main(){

    return 0;
}