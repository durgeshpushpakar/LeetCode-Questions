#include<bits/stdc++.h>
using namespace std;
vector<long long> nextLargerElement(vector<long long> arr, int n){
    stack<long long>s;
    vector<long long>ans;
    for(int i=arr.size()-1;i>=0;i--){
        if(s.empty()){
            s.push(arr[i]);
            ans.push_back(-1);
        }
        else if(s.top()>arr[i]){
            ans.push_back(s.top());
            s.push(arr[i]);
        }
        else if(s.top()<arr[i]){
            while(!s.empty() && s.top()<arr[i]){
                s.pop();
            }
            if(s.empty()){
                s.push(arr[i]);
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
                s.push(arr[i]);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}