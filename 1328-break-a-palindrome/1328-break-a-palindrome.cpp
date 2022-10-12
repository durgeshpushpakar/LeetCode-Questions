class Solution {
public:
    string breakPalindrome(string s) {
        int n=s.length();
        int temp=-1;
        if(n%2==1)temp=n/2;
        if(n==1)return "";
        for(int i=0;i<n;i++){
            if(s[i]!='a' && i!=temp){
                s[i]='a';
                return s;
            }
        }
        s[n-1]='b';
        return s;
    }
};