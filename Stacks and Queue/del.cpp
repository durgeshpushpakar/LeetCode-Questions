#include<bits/stdc++.h>
using namespace std;
int main()
{
    // vector<int>arr={1,2,3,4,5,6};
    string arr="123456";
    auto it1=upper_bound(arr.begin(), arr.end(), '4'); // gives 5
    auto it2=lower_bound(arr.begin(), arr.end(), '4'); // gives 4
    cout<<*it1<<endl<<*it2;
    return 0;
}