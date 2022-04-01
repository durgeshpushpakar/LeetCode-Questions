#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // split by slashes search for '..' or '.' else just the file names
    // then push it into the stack
    string simplifyPath(string s) {
        stack<string>st;
        int n=s.length();
        string ans="";
        for(int i=0;i<n;){
            int start=i, end;
            if(s[start]=='/'){
                while(start<n &&s[start]=='/')start++;
            }
            end=start;
            while(end<n && s[end]!='/')end++;
            if(start==end)break;
            string fileName=s.substr(start, end-start);
            if(fileName=="."){}
            else if(fileName == ".." ){
                if(!st.empty())st.pop();                
            }
            else {
                st.push(fileName);
            }
            i=end;
            continue;
        }
        while(!st.empty()){
            if(st.top()!="")ans='/' + st.top() + ans;
            st.pop();
        }
        return (ans.empty()) ? "/" : ans;
    }
};
int main()
{
	Solution S;
	cout<<S.simplifyPath("//home/");
	return 0;
}