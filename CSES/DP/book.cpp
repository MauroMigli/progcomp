#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin >> n >> x;
    vector<pair<int, int>> A(n);
    
    rep(i, n) cin >> A[i].first;
    rep(i, n) cin >> A[i].second;
    
    deque<vector<int>> memo;
    
    // Caso base
    vector<int> row_0(x + 1, 0);
    rep(b, x + 1) row_0[b] = A[0].first <= b ? A[0].second : 0;
    memo.push_front(row_0);

    rep(i, n - 1){
        vector<int> row_1(x + 1, 0);
        
        auto [h, s] = A[i + 1];
        

        for(int b = 0; b <= x; b++){
            if (b < h) row_1[b] = memo.back()[b];
            else row_1[b] = max(memo.back()[b], memo.back()[b - h] + s);
        }
        memo.push_front(row_1);
        memo.pop_back();
    }

    cout << memo.front()[x] << '\n';

    return 0;
}