#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

int gauss(int n){
    if (n % 2 == 0) return n / 2 * (n + 1);
    else return n * ((n + 1) / 2);
}

void solve() {
    int D, left_down, left_up, U, right_up, right_down;
    cin >> D >> left_down >> left_up >> U >> right_up >> right_down;
    
    int D_max = max(left_down, right_down);
    int D_min = min(left_down, right_down);
    
    int U_max = max(left_up, right_up);
    int U_min = min(left_up, right_up);


    int A1 = 2 * (gauss(D + D_min - 1) - gauss(D - 1)) + D_min;
    int A2 = 2 * (D_max - D_min) * (D + D_min);
    int B1 = 2 * (gauss(U + U_min - 1) - gauss(U - 1)) + U_min;
    
    cout << A1 + A2 + B1 << endl;
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