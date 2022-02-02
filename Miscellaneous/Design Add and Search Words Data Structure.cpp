#include<bits/stdc++.h>
using namespace std;
class TrieNode{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char x){
        this->data=x;
        isTerminal=false;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++)children[i]=NULL;
    }
};
class WordDictionary {
    TrieNode *root;
    void addWordHelper(TrieNode *root, string word){
        if(word==""){
            root->isTerminal=true;
            return;
        }
        if(root->children[word[0]-'a']==NULL){
            root->children[word[0]-'a']=new TrieNode(word[0]);
            addWordHelper(root->children[word[0]-'a'], word.substr(1));
        }
        else{
            addWordHelper(root->children[word[0]-'a'], word.substr(1));
        }
    }
    bool searchHelper(TrieNode *root, string word){
        if(word==""){
            if(root->isTerminal)return true;
            return false;
        }
        if(word[0]=='.'){
            int i;
            for(i=0;i<26;i++){
                if(root->children[i]!=NULL){
                    bool smallAns=searchHelper(root->children[i], word.substr(1));
                    if(smallAns)return true;
                }
            }
            return false;
        }
        else if(root->children[word[0]-'a']!=NULL){
            return searchHelper(root->children[word[0]-'a'], word.substr(1));
        }
        return false;
    }
public:
    WordDictionary() {
        root=new TrieNode('\0');
    }
    
    void addWord(string word) {
        addWordHelper(root, word);
    }
    
    bool search(string word) {
        return searchHelper(root, word);
    }
};

int main()
{

    return 0;
}