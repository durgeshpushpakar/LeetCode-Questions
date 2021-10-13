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
        // if(s1.empty())return;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    int peek() {
        if(s1.empty())return NULL;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s2.top();
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