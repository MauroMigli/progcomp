#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repk(i, k, n) for(int i = k; i < n; i++)


vector<pair<int, int>> prime_factorization(int n){
    vector<pair<int, int>> pf;
    int n_copy = n;

    int exp = 0;
    while(n_copy % 2 == 0){
        exp++;
        n_copy /= 2;
    } if (exp) pf.push_back({2, exp});

    for(int base = 3; base * base  <= n_copy; base += 2){
        exp = 0;

        while(n_copy % base == 0) {
            exp++;
            n_copy /= base;
        }
        if (exp) pf.push_back({base, exp});
    }

    if (n_copy > 1) pf.push_back({n_copy, 1});
    return pf;
}

void solve(){
    int n; cin >> n;
    vector<int> A(n); rep(i, n) cin >> A[i];
    vector<vector<pair<int, int>>> pf(n);

    rep(i, n) pf[i] = prime_factorization(A[i]);

    // Check if non decreasing
    bool non_decreasing = true;
    repk(i, 1, n) {
        if (A[i] <A[i - 1]) {
            non_decreasing = false;
            break;
        }
    }

    if (non_decreasing) {
        cout << "Bob\n";
        return;
    }

    int prev_prime = 1;
    rep(i, n){
        int new_prime = 1;
        if (pf[i].size() > 1) {
            cout << "Alice\n";
            return;
        } else if (pf[i].size() == 1) new_prime = pf[i][0].first;

        if (new_prime < prev_prime){
            cout << "Alice\n";
            return;
        } else prev_prime = new_prime;
    }
    cout << "Bob\n";
}

int main(){
    int t; cin >> t;

    while(t--) solve();
    

    return 0;
}