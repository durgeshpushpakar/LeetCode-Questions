// https://www.lintcode.com/problem/872/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> mp;
    void visit(vector<int> &pid, vector<int> &ppid, int tarInd, int kill) {
        if(pid[tarInd]==kill || pid[tarInd]<0) return;
        pid[tarInd]=-pid[tarInd];
        for(auto &i: mp[abs(pid[tarInd])]) {
            visit(pid, ppid, i, kill);
        }
    }
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        for(int i=0;i<pid.size();i++) mp[ppid[i]].push_back(i);
        vector<int> ans;
        visit(pid, ppid, mp[0][0], kill);
        for(auto &i: pid) if(i>0) ans.push_back(i);
        return ans;
    }
};
int main()
{

    return 0;
}