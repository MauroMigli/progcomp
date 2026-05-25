#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n; cin >> n;
    vector<pair<int, int>> A(n);
    rep(i, n) cin >> A[i].first;
    rep(i, n) cin >> A[i].second;

    int K, L; cin >> K >> L;
    vector<int> A_sub(2 * K - 1);
    vector<int> B_sub(2 * K - 1);

    for(int i = 0; i < 2 * K - 1; i++){
        A_sub[i] = A[(i + n - K) % (n - 1)].first;
        B_sub[i] = A[(i + n - K) % (n - 1)].first;
    }

    
    return 0;
}