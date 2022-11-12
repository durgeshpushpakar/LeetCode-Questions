class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(), si=0, maxLen=1;
        for(int i=1;i<n;i++){
            int j=i-1, k=i+1;
            while(j>=0 && k<n && s[j]==s[k]){
                if(k-j+1>maxLen){
                    maxLen=k-j+1;
                    si=j;
                }
                k++;j--;
            }
            j=i-1;k=i;
            while(j>=0 && k<n && s[j]==s[k]){
                if(k-j+1>maxLen){
                    maxLen=k-j+1;
                    si=j;
                }
                k++;j--;
            }
        }
        return s.substr(si, maxLen);
    }
};