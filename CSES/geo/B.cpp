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

void solve(){
    pt p1, p2, q1, q2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> q1.x >> q1.y >> q2.x >> q2.y;


    if (lines_intersect(p1, p2, q1, q2)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}