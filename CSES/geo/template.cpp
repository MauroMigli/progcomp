#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

// CHANGE ld -> ll IF NECESSARY

ll INF = 1e15;
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

int turn(pt a, pt b, pt c) { return sgn(cross(b - a, c - b)); }

bool lines_intersect(pt p1, pt p2, pt q1, pt q2){
    pt l1 = p2 - p1;
    pt l2 = q2 - q1;

    int dir1 = dir(l2, p1 - q1);
    int dir2 = dir(l2, p2 - q1);
    int dir3 = dir(l1, q1 - p1);
    int dir4 = dir(l1, q2 - p1);

    if (dir1 == 0 && dir2 == 0 && dir3 == 0 && dir4 == 0){
        if (p2 < p1) swap(p1, p2);
        if (q2 < q1) swap(q1, q2);

        return !(p2 < q1 || q2 < p1);
    }
    return (dir1 != dir2 && dir3 != dir4);   
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

// integer points
pair<ll, ll> polygon_lattice_points(const vector<pt>& P){
    int n = (int)P.size();
    ll B = 0;
    rep(i, n){
        pt d = P[(i + 1) % n] - P[i];
        B += gcd(d.x, d.y);
    }
    
    // PICK'S THEOREM
    ll Ax2 = polygon_area_x2(P);
    ll Ix2 = Ax2 - B + 2;
    return {Ix2 / 2, B};
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


// CONVEX HULL

vector<pt> convex_hull(vector<pt> P){
    int n = (int)P.size();
    sort(P.begin(), P.end());
    vector<pt> h;
    
    rep(i, n){
        while((int)h.size() >= 2 && turn(h[(int)h.size() - 2], h[(int)h.size() - 1], P[i]) == -1){
            h.pop_back();
        }
        h.push_back(P[i]);
    }

    int lower_hull_size = (int)h.size();
    for(int i = n - 2; i >= 0; i--){
        while((int)h.size() > lower_hull_size && turn(h[(int)h.size() - 2], h[(int)h.size() - 1], P[i]) == -1) {
            h.pop_back();
        }
        h.push_back(P[i]);
    }

    // se aniade el ultimo punto dos veces
    h.pop_back();
    return h;
}