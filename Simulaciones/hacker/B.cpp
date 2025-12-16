#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

void solve(int i){
    int n, m; cin >> n >> m;

    vector<int> A(n), B(m);
    rep(i, n) cin >> A[i];
    rep(j, m) cin >> B[j];

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int l = 0, r = n - 1;
    int mid;

    while (l < r){
        mid = l + (r - l) / 2;

        
    }
}

int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
    
    return 0;
}