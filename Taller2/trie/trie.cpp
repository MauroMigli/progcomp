#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        Node* hijos[26];
        bool end;

        Node() {
            end = false;
            for (int i = 0; i < 26; i++) hijos[i] = nullptr;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    // Inserta una palabra en el trie
    void insert(const string &s) {
        Node* cur = root;
        for (char c : s) {
            int idx = c - 'a';
            if (cur->hijos[idx] == nullptr)
                cur->hijos[idx] = new Node();
            cur = cur->hijos[idx];
        }
        cur->end = true;
    }

    // Busca si una palabra está exactamente en el trie
    bool search(const string &s) {
        Node* cur = root;
        for (char c : s) {
            int idx = c - 'a';
            if (cur->hijos[idx] == nullptr)
                return false;
            cur = cur->hijos[idx];
        }
        return cur->end;
    }

    // Verifica si existe alguna palabra que comience con un prefijo dado
    bool starts_with(const string &s) {
        Node* cur = root;
        for (char c : s) {
            int idx = c - 'a';
            if (cur->hijos[idx] == nullptr)
                return false;
            cur = cur->hijos[idx];
        }
        return true;
    }
};

int main() {
    Trie t;

}
