#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    int size;
    MedianFinder(){
        size=0;
    }
    
    void addNum(int num) {
        if(size==0)maxHeap.push(num);
        else if(num>maxHeap.top()){
            minHeap.push(num);
            if(minHeap.size()-maxHeap.size()>1){
                int x=minHeap.top();
                minHeap.pop();
                maxHeap.push(x); 
            }
        }
        else{
            maxHeap.push(num);
            if(maxHeap.size()-minHeap.size()>1){
                int x=maxHeap.top();
                maxHeap.pop();
                minHeap.push(x); 
            }
        }
        size++;
    }
    
    double findMedian() {
        if(size%2==1){
            if(maxHeap.size()>minHeap.size())return maxHeap.top();
            else return minHeap.top();
        }
        else{
            return (minHeap.top()+maxHeap.top()+0.0)/2.0;
        }
    }
};