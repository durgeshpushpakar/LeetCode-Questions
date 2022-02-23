// https://leetcode.com/problems/clone-graph/
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<Node*, Node*>copies;
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        if(!copies.count(node)){
            copies[node]=new Node(node->val, {});
            for(int i=0;i<node->neighbors.size();i++){
                copies[node]->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
        }
        return copies[node];
    }
};