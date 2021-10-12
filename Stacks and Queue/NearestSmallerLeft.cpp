#include<bits/stdc++.h>
using namespace std;
vector<int>NSL(int *arr, int n){
    stack<int>s;
    vector<int>left;
    for(int i=0;i<n;i++){
        if(s.empty())left.push_back(-1);
        else if(arr[i]>arr[s.top()])left.push_back(s.top());
        else{
            while(!s.empty() && arr[s.top()]>=arr[i])s.pop();
            if(s.empty())left.push_back(-1);
            else left.push_back(s.top());
        }
        s.push(i);
    }
    return left;
}
int main()
{

    return 0;
}