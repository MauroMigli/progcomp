#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define PRINT_ARR(arr, n) do { \
    std::cerr << #arr << " = ["; \
    for (int _i = 0; _i < (int)(n); ++_i) \
        std::cerr << (_i ? ", " : "") << (arr)[_i]; \
    std::cerr << "]\n"; \
} while (0)

vector<vector<int>> dices;
vector<bool> generated;
int n;

int digits_to_num(vector<int> digits){
    int pot_10 = 1;
    int ret = 0;
    rep(i, (int)digits.size()){
        if (digits[i] == -1) break;
        ret += digits[i] * pot_10;
        pot_10 *= 10;
    }
    return ret;
}

void backtracking(vector<int>& digits, set<int>& selection, int dig){
    if (dig > 0) generated[digits_to_num(digits)] = true;
    
    rep(dice, n){
        if (selection.count(dice)) continue;
        for(int a : dices[dice]){
            digits[dig] = a;
            selection.insert(dice);
            
            backtracking(digits, selection, dig + 1);
            
            digits[dig] = -1;
            selection.erase(dice);
        }

    }

}

void solve() {
    cin >> n;
    dices.assign(n, vector<int>(6, 0));
    rep(i, n) rep(j, 6) cin >> dices[i][j];
    
    generated.assign(1001, false);
    vector<int> digits(n, -1);
    set<int> selection;
    backtracking(digits, selection, 0);

    
    repk(i, 1, 1001){
        if (!generated[i]){
            cout << i - 1 << endl;
            return;
        }
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