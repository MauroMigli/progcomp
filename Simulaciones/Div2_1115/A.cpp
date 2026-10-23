#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    multiset<int> ms;
    int size = 0;
    int prev = -1;

    rep(i, n){
        int a; cin >> a;
        ms.insert(a);
        if (a != prev) size++;
        prev = a;
    }

    if (size == 1){
        int x = *ms.begin();
        if (ms.count(x) == 1{
            cout << 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}