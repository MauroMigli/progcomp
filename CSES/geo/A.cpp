#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

const ld EPS = 1e-9;
int sgn(ld x) { return (x > EPS) - (x < -EPS); }

struct pt {
    ld x, y;

    pt operator+(pt A) const { return {x + A.x, y + A.y}; }
    pt operator-(pt A) const { return {x - A.x, y - A.y}; }
    pt operator*(ld k) const { return {x * k, y * k}; }
    bool operator==(pt A) const { return sgn(x - A.x) == 0 && sgn(y - A.y); }
    bool operator<(pt A) const { return sgn(x - A.x) ? x < A.x : sgn(y - A.y) < 0; }
};

ld dot(pt a, pt b)   { return a.x * b.x + a.y * b.y; }
ld cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }

void solve(){
    pt p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

    pt v = p2 - p1, u = p3 - p1;
    
    if (cross(v, u) > 0) cout << "LEFT\n";
    else if (cross(v, u) == 0) cout << "TOUCH\n";
    else cout << "RIGHT\n";
}

int main(){
    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}