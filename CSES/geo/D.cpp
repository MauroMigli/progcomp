#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

const ll EPS = 1e-9;
int sgn(ll x) { return (x > EPS) - (x < -EPS); }
ll INF = 2e9;

struct pt {
    ll x, y;

    pt operator+(pt A) const { return {x + A.x, y + A.y}; }
    pt operator-(pt A) const { return {x - A.x, y - A.y}; }
    pt operator*(ll k) const { return {x * k, y * k}; }
    pt& operator+=(pt A) { x += A.x; y += A.y; return *this; };
    pt& operator-=(pt A) { x -= A.x; y -= A.y; return *this; };
    pt& operator*=(ll k) { x *= k; y *= k; return *this; };

    bool operator==(pt A) const { return sgn(x - A.x) == 0 && sgn(y - A.y) == 0; }
    bool operator<(pt A) const { return sgn(x - A.x) ? x < A.x : sgn(y - A.y) < 0; }
};

ll dot(pt a, pt b)   { return a.x * b.x + a.y * b.y; }
ll cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }

int dir(pt a, pt b) {
    ll det = cross(a, b);
    return sgn(det);
}

bool lines_intersect(pt p1, pt p2, pt q1, pt q2){
    pt l1 = p2 - p1;
    pt l2 = q2 - q1;

    int dir1 = dir(l2, p1 - q1);
    int dir2 = dir(l2, p2 - q1);
    int dir3 = dir(l1, q1 - p1);
    int dir4 = dir(l1, q2 - p1);


    if (dir1 == 0 && dir2 == 0 && dir3 == 0 && dir4 == 0) return false;
    if (dir1 == 0 && dir2 == 0 && dir3 == 0 && dir4 == 0){
        if (p2 < p1) swap(p1, p2);
        if (q2 < q1) swap(q1, q2);

        return !(p2 < q1 || q2 < p1);
    }
    return (dir1 != dir2 && dir3 != dir4);   
}

// 0 -> outside
// 1 -> inside
// 2 -> boundary

int locate_in_polygon(const vector<pt>& P, pt p){
    int n = (int)P.size();
    pt x_infty = pt{INF, 0};

    bool is_in = false;

    rep(i, n){
        pt a = P[i], b = P[(i + 1) % n];
        if (cross(b - a, p - a) == 0 && dot(a - p, b - p) <= 0) {
            return 2;
        }

        if (a.y > p.y != b.y > p.y && lines_intersect(p, p + x_infty, a, b)) {
            is_in = !is_in;
        }
    }

    return is_in;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<pt> P(n); 
    rep(i, n) cin >> P[i].x >> P[i].y;

    while(m--){
        pt p; cin >> p.x >> p.y;
        
        int location = locate_in_polygon(P, p);
        if (location == 0) cout << "OUTSIDE\n";
        else if (location == 1) cout << "INSIDE\n";
        else cout << "BOUNDARY\n";
    }

    return 0;
}