#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
ll M = 1e9 + 7;

int n;
vector<vector<int>> memo;
vector<string> A;

int dp(int i, int j){
    if (memo[i][j] != -1) return memo[i][j];
    if (i == n - 1 && j == n - 1) return memo[i][j] = 1;

    int count = 0;
    if (i < n - 1) {
        if (A[i + 1][j] != '*') count = (count + dp(i + 1, j)) % M;
    }
    if (j < n - 1) {
        if ((A[i][j + 1] != '*')) count = (count + dp(i, j + 1)) % M;
    }
    return memo[i][j] = count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    A.assign(n, ""); rep(i, n) cin >> A[i];
    memo.assign(n, vector<int>(n, -1));

    if (A[0][0] == '*') cout << 0 << '\n';
    else cout << dp(0, 0) << '\n';
    return 0;
}