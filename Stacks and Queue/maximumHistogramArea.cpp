// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
#include<bits/stdc++.h>
using namespace std;
vector<long long>NSR(long long *arr, int n){
    stack<long long>s;
    vector<long long>right;
    for(long long i=n-1;i>=0;i--){
        if(s.empty())right.push_back(n);
        else if(arr[i]>arr[s.top()])right.push_back(s.top());
        else{
            while(!s.empty() && arr[s.top()]>=arr[i])s.pop();
            if(s.empty())right.push_back(n);
            else right.push_back(s.top());
        }
        s.push(i);
    }
    reverse(right.begin(), right.end());
    return right;
}
vector<long long>NSL(long long *arr, int n){
    stack<long long>s;
    vector<long long>left;
    for(long long i=0;i<n;i++){
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
long long getMaxArea(long long arr[], int n){
    long long maxArea=0;
    vector<long long>left=NSL(arr, n);
    vector<long long>right=NSR(arr, n);
    // for(int i=0;i<n;i++)cout<<left
    for(int i=0;i<n;i++){
        long long diff=right[i]-left[i];
        long long area=arr[i]*(diff-1);
        maxArea=max(area, maxArea);
    }
    return maxArea;
}

int main(){
    long long arr[7]={6,2,5,4,5,1,6};
    cout<<"maxArea: "<<getMaxArea(arr, 7)<<endl;
    return 0;
}