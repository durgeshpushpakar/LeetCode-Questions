// Minimum Cost to Set Cooking Time
// https://leetcode.com/contest/biweekly-contest-71/problems/minimum-cost-to-set-cooking-time
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int calcCost(int min, int sec, int startAt, int moveCost, int pushCost){
    int ans=0;
    if(min!=0){
        if(min<10){
            if(startAt==min)ans+=pushCost;
            else ans+=moveCost+pushCost;
        }
        else{
            string temp=to_string(min);
            ans+= 2*(moveCost+pushCost);
            if(atoi(temp[0]==startAt))ans-=moveCost;
        }
    }
    if(sec!=0){
        if(sec!=)
    }
}
int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
    if(targetSeconds==6039)return calcCost(99, 99, startAt, moveCost, pushCost);   
}
};
int main()
{

    return 0;
}