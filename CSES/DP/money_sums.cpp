#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

int n;
vector<int> A;

set<int> dp(int i){
    if (i == 0) return {A[0]};
    
    set<int> prev = dp(i - 1);

    auto it = prev.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    A.assign(n, 0); rep(i, n) cin >> A[i];



    return 0;
}