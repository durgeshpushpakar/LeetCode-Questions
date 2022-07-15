#include<bits/stdc++.h>
using namespace std;
int shuffle(int n){
    string num=to_string(n);
    num=num.back()+num;
    num.pop_back();
    return stoi(num);
}
int minimumCoins(int n, int x){
    // BFS Brute Force
    int level=0;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            int front=q.front();
            q.pop();
            int num1=shuffle(front), num2=front*x;
            if(num1==n || num2==x)return level+1;
            if(front>10 && front%10!=0 && num1<=1e6)q.push(num1);
            if(num2<=1e6)q.push(num2);        
        }
        level++;
    }
    return -1;
}
int main()
{
    cout<<shuffle(12334)<<endl;
    return 0;
}