// https://leetcode.com/problems/word-ladder/
#include<bits/stdc++.h>
using namespace std;
// BFS Approach
class Solution {
public:
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, bool>wordMap;
    queue<string>q;   
    for(int i=0;i<wordList.size();i++){
        wordMap[wordList[i]]=false;
    }
    q.push(beginWord);
    if(wordMap.count(beginWord))wordMap[beginWord]=true;
    int count=1;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            string front=q.front();
            q.pop();
            for(int j=0;j<front.length();j++){
                for(char c='a';c<='z';c++){
                    string temp=front;
                    temp[j]=c;
                    if(wordMap.count(temp) && !wordMap[temp]){
                        if(temp==endWord)return count+1;
                        q.push(temp);
                        wordMap[temp]=true;
                    }
                }
            }
        }
        count++;
    }
    return 0;
}
};
int main()
{

    return 0;
}