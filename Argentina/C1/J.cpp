#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    vector<p> A(n);
    vector<p> extremos(n);
    vector<int> inicio;

    rep(i, n){
        cin >> A[i].first >> A[i].second;
        A[i].first--; A[i].second--;
        if (A[i].first == -1) inicio.push_back(i);
    }

    for(int idx : inicio){
        int curr = idx;
        while(A[curr].second != -1){
            extremos[curr].first = idx;
            curr = A[curr].second;
        }
        extremos[curr].first = idx;

        int end = curr;
        while(A[curr].first != -1){
            extremos[curr].second = end;
            curr = A[curr].first;
        }
        extremos[curr].second = end;
    }

    rep(i, n){
        rep(j, n){
            if (i == j) continue;
            if (A[i].second == -1 && A[j].first == -1 && i != extremos[j].second && j != extremos[i].first){
                A[i].second = j; A[j].first = i;
            }
        }
    }
    rep(i, n){
        cout << A[i].first + 1 << ' ' << A[i].second + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}