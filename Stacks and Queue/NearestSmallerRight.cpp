#include<bits/stdc++.h>
using namespace std;
vector<int>NSR(int *arr, int n){
    stack<int>s;
    vector<int>right;
    for(int i=n-1;i>=0;i--){
        if(s.empty())right.push_back(n);
        else if(arr[i]>arr[s.top()])right.push_back(s.top());
        else{
            while(!s.empty() && arr[s.top()]>=arr[i])s.pop();
            if(s.empty())right.push_back(n);
            else right.push_back(s.top());
        }
        s.push(i);
    }
    return right;
}