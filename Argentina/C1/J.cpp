#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    
    vector<p> list(n);
    rep(i, n) {
        cin >> list[i].first  >> list[i].second;
    }
    
    vector<bool> visited(n, false);
    vector<p> components;
    
    rep(i, n){
        if (list[i].first != 0) continue;
        if (visited[i]) continue;
        
        visited[i] = true;
        int curr_idx = i;
        while(list[curr_idx].second != 0){
            curr_idx = list[curr_idx].second - 1;
            visited[curr_idx] = true;
        }

        components.push_back({i, curr_idx});
    }
    
    rep(i, (int)components.size() - 1){
        auto [l, r] = components[i];
        auto [l_next, r_next] = components[i + 1];
        
        list[r].second = l_next + 1;
        list[l_next].first = r + 1;
    }

    for(auto [l, r] : list){
        cout << l << ' ' << r << '\n';
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