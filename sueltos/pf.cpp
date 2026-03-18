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
        base += 2;
    }

    if (n_copy > 1) pf.push_back({n_copy, 1});
    return pf;
}