#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    int count;
    TrieNode* hijos[26]; // tamano del abcdario


    TrieNode(){
        count = 0;

        for(int i = 0; i < 26; i++){
            hijos[i] = nullptr;
        }
    }
    ~TrieNode() {
        for(int i = 0; i < 26; i++){
            if (hijos[i] != nullptr) delete hijos[i];
        }
    }

    bool hijo_existe(int i){
        return hijos[i] != nullptr;
    }
};

void insert(TrieNode* root, string s){
    TrieNode* curr = root;

    for(char c : s){
        int idx = c - 'a';
        if (!curr->hijo_existe(idx)) curr->hijos[idx] = new TrieNode;
        curr = curr->hijos[idx];
    }
    curr->count++; // es el final de la palabra el que marcamos.
}