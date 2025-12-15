#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repf(i, k, n) for (int i = k; i < (n); i++)
const ll MOD = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> A(n);
    vector<int> freq(n + 1);
    int distinct = 0;
    
    rep(i, n) {
        cin >> A[i];
        if (freq[A[i]] == 0){
            distinct++;
        }
        freq[A[i]]++;
    }

    int prev_2 = A[n - 2];
    int prev = A[n - 1];

    if (distinct != n) {
        repf(i, 1, n + 1){
            if (freq[i] == 0 && k > 0) {
                cout << i << " ";
                prev_2 = prev;
                prev = i;
                k--;
            }
        }
    }
    rep(j, k){ // 
        repf(i, 1, n + 1){ // candidato prox numero
            if (i != prev_2 && i != prev){
                prev_2 = prev;
                prev = i;
                cout << i << " ";
                break;
            }
        }
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}