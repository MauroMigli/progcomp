#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)

ll INF = 1e18;
ld EPS = 1e-9;
int sgn(ll x) { return (x > EPS) - (x < -EPS); }

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
    return sgn(cross(a, b));
}

int turn(pt a, pt b, pt c) { return sgn(cross(b - a, c - b)); }

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

int main(){
    int n; cin >> n;
    vector<pt> P(n);
    rep(i, n) cin >> P[i].x >> P[i].y;
    
    vector<pt> H = convex_hull(P);
    cout << (int)H.size() << '\n';
    
    for(pt p : H) cout << p.x << ' ' << p.y << '\n';
    return 0;
}