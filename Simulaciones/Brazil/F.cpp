#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, c; cin >> n >> c;
    
    vector<string> A(n);
    unordered_map<string, int> freq;
    rep(i, n) {
        cin >> A[i];
        
        rep(j, c){
            if (A[i][j] == '*'){
                rep(k, 26){
                    string nueva = A[i].substr(0, j) + char(k + (int)'a') + A[i].substr(j + 1, c - j - 1);
                    freq[nueva]++;
                }
            }
        }
    }

    string candidato = "";
    int maximo = 0;
    for(auto [s, f] : freq){
        if (f > maximo || (f == maximo && s < candidato)){
            candidato = s;
            maximo = f;
        }
    }
    cout << candidato << " " << maximo << endl;

    return 0;
}