#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    set<string> conj = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC"};
    
    if (conj.count(s)) {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}