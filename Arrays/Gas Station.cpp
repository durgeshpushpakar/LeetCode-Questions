#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0, end=0;
        int currGas=0, totalGasleft=0;
        for(int i=0;i<gas.size();i++){
            currGas+=gas[i]-cost[i];
            totalGasleft+=gas[i]-cost[i];
            if(currGas<0){
                currGas=0;
                start=i+1;
            }
        }
        if(totalGasleft<0)return -1;
        return start;
    }
};
int main()
{

    return 0;
}