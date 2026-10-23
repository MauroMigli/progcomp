#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

const ld EPS = 1e-9;
int sgn(ld x) { return (x > EPS) - (x < -EPS); }

struct pt {
    ld x, y;
    pt operator+(pt o) const { return {x + o.x, y + o.y}; }
    pt operator-(pt o) const { return {x - o.x, y - o.y}; }
    pt operator*(ld k)  const { return {x * k, y * k}; }
    bool operator==(pt o) const { return sgn(x - o.x) == 0 && sgn(y - o.y) == 0; }
    bool operator<(pt o) const { return sgn(x - o.x) ? x < o.x : sgn(y - o.y) < 0; }
};
ld dot(pt a, pt b)   { return a.x * b.x + a.y * b.y; }
ld cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }

// > 0: c is left of a->b (CCW), < 0: right (CW), 0: collinear
ld orient(pt a, pt b, pt c) { return cross(b - a, c - a); }

// closest point on segment ab to p
pt closest_on_segment(pt a, pt b, pt p) {
    if (a == b) return a;
    ld t = dot(p - a, b - a) / dot(b - a, b - a);
    t = max((ld)0, min((ld)1, t));
    return a + (b - a) * t;
}

// Andrew's monotone chain. Returns hull CCW, without collinear points
vector<pt> convex_hull(vector<pt> P) {
    sort(all(P));
    P.erase(unique(all(P)), P.end());
    int n = P.size(), k = 0;
    if (n < 3) return P;
    vector<pt> H(2 * n);
    rep(i, n) {
        while (k >= 2 && sgn(orient(H[k - 2], H[k - 1], P[i])) <= 0) k--;
        H[k++] = P[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && sgn(orient(H[k - 2], H[k - 1], P[i])) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k - 1);
    return H;
}

void solve() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);

    solve();

    return 0;
}
