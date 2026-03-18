#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;

    int ans = 0;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    vector<int> queue = {A[0]};
    repk(i, 1, n){
        int l = 0, r = (int)queue.size() - 1;
        int mid;

        while(l < r){
            mid = l + (r - l) / 2;

            if (A[i] < queue[mid]) r = mid;
            else l = mid + 1;
        }

        if (A[i] > queue[l]) queue.push_back(A[i]);
        else queue[l] = A[i]; 
    }
    cout << queue.size() << endl;
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