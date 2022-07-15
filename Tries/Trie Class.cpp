#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* links[26];
    bool terminal;
    Node(){
        terminal=false;
        memset(links, NULL, sizeof links); // IMP line by default CPP doesnt initialise array with NULL
    }
    void put(char x, Node* node){
        links[x-'a']=node;
    }
    
    Node*get(char x){
        return links[x-'a'];
    }
    
    bool containsKey(char x){
        return links[x-'a']!=NULL;
    }
};
class Trie {
    Node*root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!( node->containsKey(word[i]) )){
                node->put(word[i], new Node());
            }
            node=node->get(word[i]);
        }
        node->terminal=true;
    }
    
    bool search(string word) {
        Node*node=root;
        for(int i=0;i<word.length();i++){
            if(!(node->containsKey(word[i])))return false;
            node=node->get(word[i]);
        }
        return node->terminal;
    }
    
    bool startsWith(string word) {
        Node*node=root;
        for(int i=0;i<word.length();i++){
            if(!(node->containsKey(word[i])))return false;
            node=node->get(word[i]);
        }
        return true;
    }
};
int main()
{
    
    return 0;
}