#include<bits/stdc++.h>
using namespace std;
vector <int> calculateSpan(int price[], int n){
    stack<int>s;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(s.empty()){
            ans.push_back(1);
            s.push(i);
        }
        if(price[i]<price[s.top()]){
            ans.push_back(1);
            s.push(i);
        }
        else{
            while(!s.empty() && price[i]>=price[s.top()])s.pop();
            if(s.empty()){
                ans.push_back(i+1);
                s.push(price[i]);
            }
            else{
                ans.push_back(i-s.top());
                s.push(i);
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}