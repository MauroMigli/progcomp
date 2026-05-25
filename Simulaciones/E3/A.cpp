#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repk(i, k, n) for(int i = k; i < n; i++)

int main(){
    string s; cin >> s;
    set<char> conj = {'a', 'e', 'i', 'o', 'u'};
    for(char x : s){
        if (!conj.count(x)){
            cout << x;
        }
    }
    cout << endl;
    
    return 0;
}