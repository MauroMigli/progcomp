#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
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
    pt& operator+=(pt A) { x += A.x; y += A.y; return *this; };
    pt& operator-=(pt A) { x -= A.x; y -= A.y; return *this; };
    pt& operator*=(ld k) { x *= k; y *= k; return *this; };

    bool operator==(pt A) const { return sgn(x - A.x) == 0 && sgn(y - A.y) == 0; }
    bool operator<(pt A) const { return sgn(x - A.x) ? x < A.x : sgn(y - A.y) < 0; }
};

ld dot(pt a, pt b)   { return a.x * b.x + a.y * b.y; }
ld cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }

int dir(pt a, pt b) {
    ld det = cross(a, b);
    return sgn(det);
}

// THIS GIVES 2 x A
ll polygon_area_x2(const vector<pt>& P){
    int n = (int)P.size();
    ll area_x2 = 0;
    rep(i, n){
        pt u = P[i], v = P[(i + 1) % n];

        area_x2 += cross(u, v);
    }
    return abs(area_x2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<pt> P(n);
    rep(i, n) cin >> P[i].x >> P[i].y;

    ll area_x2 = polygon_area_x2(P);

    cout << fixed << setprecision(0) << fabsl(area_x2) << '\n';
    return 0;
}