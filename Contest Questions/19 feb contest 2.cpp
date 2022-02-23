#include<bits/stdc++.h>
using namespace std;
// Input: num = 33
// Output: [10,11,12]
class Solution {
public:
vector<long long> sumOfThree(long long num) {
    vector<long long>ans;
    if((num-3)%3==0){
        long long temp=(num-3)/3;
        ans.insert(ans.end(),{temp, temp+1, temp+2});
    }
    return ans;
}
};