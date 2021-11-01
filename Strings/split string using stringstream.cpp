#include<bits/stdc++.h>
using namespace std;

int main()
{
string str = "1,2,3,4,5,6";
    vector<string> v;
 
    stringstream ss(str);
 
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
    }
 
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    return 0;
}