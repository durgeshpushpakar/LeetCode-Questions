#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int minimumSum(int num) {
    string n=to_string(num);
    sort(n.begin(), n.end());
    int num1=0, num2=0;
    num1=(10*(n[0]-'0'))+(n[3]-'0');
    num2=(10*(n[1]-'0'))+(n[2]-'0');
    return num1+num2;
}

};
int main()
{

    return 0;
}