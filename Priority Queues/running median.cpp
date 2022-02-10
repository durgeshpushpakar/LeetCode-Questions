#include<bits/stdc++.h>
using namespace std;
void findMedian(int *arr, int n){
    if(n==0)return;
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    maxHeap.push(arr[0]);
    cout<<arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>maxHeap.top()){
            minHeap.push(arr[i]);
            if(minHeap.size()-maxHeap.size()>1){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            if(minHeap.size()==maxHeap.size()){
                int median=(minHeap.top()+maxHeap.top())/2;
                cout<<" "<<median;
            }
            else if(minHeap.size()-maxHeap.size()==1){
                cout<<" "<<minHeap.top();
            }
        }
        else{
            maxHeap.push(arr[i]);
            if(maxHeap.size()-minHeap.size()>1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            if(maxHeap.size()==minHeap.size()){
                int median=(minHeap.top()+maxHeap.top())/2;
                cout<<" "<<median;
            }
            else if(maxHeap.size()-minHeap.size()==1){
                cout<<" "<<maxHeap.top();
            }
        }
    }
    return;
}
int main()
{

    return 0;
}