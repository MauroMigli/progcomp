#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

int n;

void backtracking(int i, vector<int>& stack){
    if (i == n){
        for(int x : stack) {
            cout << x;
        }
        cout << '\n';
    } else {
        stack.push_back(0);
        backtracking(i + 1, stack);
        stack.pop_back();

        stack.push_back(1);
        backtracking(i + 1, stack);
        stack.pop_back();
    }
}

void solve() {
    cin >> n;
    
    vector<int> ans;
    backtracking(0, ans);
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