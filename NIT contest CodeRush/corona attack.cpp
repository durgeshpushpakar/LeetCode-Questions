#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
long long tempo=1000000000000000001;
class Pair{
    public:
    long long x,y;
    Pair(long long a, long long b){
        x=a;
        y=b;
    }
};
long long BFSjumps(long long x, long long y){
    if(x==0 && y==0)return 0;
    queue<Pair>q;
    Pair start(0, 0);
    long long count=1;
    int directions[8][2]={
    {2,1},{2,-1},{-2,1},{-2,-1},{-1,2},{-1,-2},{1,2},{1,-2}
    };
    q.push(start);
    while(!q.empty()){
        long long size=q.size();
        for(long long i=0;i<size;i++){
            Pair front=q.front();
            q.pop();
            for(int j=0;j<8;j++){
                long long newX=front.x+directions[j][0];
                long long newY=front.y+directions[j][1];
                if(newX==x && newY==y)return count;
                Pair temp(newX, newY);
                if(newX<tempo && newY<tempo)q.push(temp);
            }
        }
        count++;
    }
    return 0;
}

int main() {
    long long t;cin>>t;
    while(t--){
        long long x, y;
        cin>>x>>y;
        cout<<BFSjumps(x, y)<<endl;
    }
    return 0;
}