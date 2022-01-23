#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string s="123456789";
        string lower=to_string(low);
        string upper=to_string(high);
        int lDigits=lower.length();
        int uDigits=upper.length();
        for(int i=lDigits;i<=uDigits;i++){
            for(int j=0;j<=9-i;j++){
                int num=stoi(s.substr(j, i));
                if(num>=low && num<=high)ans.push_back(num);
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}