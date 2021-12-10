#include<bits/stdc++.h>
using namespace std;
int search(string pat, string txt) {
    int txtLen=txt.length();
    int patLen=pat.length();
    int counter=0;
    unordered_map<char, int>patMap;
    unordered_map<char, int>txtMap;
    for(int i=0;i<patLen;i++)patMap[pat[i]]++;
    
    int i=0, j=0;
    for(j=0;j<patLen;j++){
        txtMap[txt[j]]++;
    }   
    if(txtMap==patMap)counter++;

    for(;j<txtLen;j++){
        txtMap[txt[j]]++;
        txtMap[txt[i]]--;
        if(txtMap.at(txt[i])==0)txtMap.erase(txt[i]);
        i++;
        if(txtMap==patMap)counter++;
    }
    return counter;
}

int main()
{
    string txt = "forxxorfxdofr";
    string pat = "for";
    cout<<search(pat, txt);
    return 0;
}