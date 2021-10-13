#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        for(int i=0;i<s1.size()-1;i++){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s1.top();
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    int peek() {
        for(int i=0;i<s1.size()-1;i++){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s1.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return s1.empty();
    }
};
int main()
{

    return 0;
}