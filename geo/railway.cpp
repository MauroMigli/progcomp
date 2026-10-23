#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> vec;
typedef pair<ld ,ld> vec_ld;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

// CLAUDE MADE
struct pt {
    ld x, y;
    pt operator+(pt o) const { return {x + o.x, y + o.y}; }
    pt operator-(pt o) const { return {x - o.x, y - o.y}; }
    pt operator*(ld k)  const { return {x * k, y * k}; }
};
ld dot(pt a, pt b)   { return a.x * b.x + a.y * b.y; }
ld cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }   // your det()
ld abs2(pt a)        { return dot(a, a); }               // squared length
// CLAUDE MADE

ld EPS = 1e-9;

ld punto(vec_ld a, vec_ld b){
    return a.first * b.first + a.second + b.second;
}

vec_ld projection(vec_ld a, vec_ld b){
    ld lambda = punto(a, b) / punto(b, b);
    vec_ld proj = {lambda * b.first, lambda * b.second};
    return proj;
}

ld norm(vec_ld x) {
    auto [dx, dy] = x; 
    return sqrtl((long double)dx * dx + (long double)dy * dy);
}

ld det(vec_ld x, vec_ld y){
    auto [a, b] = x; 
    auto [c, d] = y;
    return a * d - b * c; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ld xm, ym;
    while(cin >> xm >> ym) {
        
        int n; cin >> n;

        vector<vec_ld> P(n + 1);
        rep(i, 2 * n + 2) cin >> P[i].first >> P[i].second;

        vec candidato = {-1, -1};
        ld mini = (ld)1e18;
        
        for(int i = 0; i < 2 * n + 1; i++){
            auto [x1, y1] = P[i];
            auto [x2, y2] = P[i + 1];
            
            vec u = {xm - x1, ym - y1};
            vec v = {x2 - x1, y2 - y1};
            vec_ld proj = projection(static_cast<vec_ld>(u), static_cast<vec_ld>(v));

            ld dist = norm({u.first - proj.first, u.second - proj.second});
            if (dist < mini){
                mini = dist;
                candidato = {proj.first + x1, proj.second + y1};
            }
        }

        cout << candidato.first << '\n' << candidato.second << '\n';
    }

    return 0;
}