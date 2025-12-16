#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)


struct ST {
    ll n;
    vector<ll> t;     // min del rango
    vector<ll> lazy;  // pendiente (add)

    ST(const vector<ll>& a) {
        n = a.size();
        t.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(1, 0, n-1, a);
    }

    void build(ll v, ll tl, ll tr, const vector<ll>& a) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            ll tm = (tl + tr) / 2;
            build(v*2, tl, tm, a);
            build(v*2+1, tm+1, tr, a);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }

    void push(ll v) {
        if (lazy[v] != 0) {
            // Propagar lazy a ambos hijos
            lazy[v*2]     += lazy[v];
            lazy[v*2 + 1] += lazy[v];

            // Actualizar valores de los hijos
            t[v*2]     += lazy[v];
            t[v*2 + 1] += lazy[v];

            lazy[v] = 0;
        }
    }

    void update(ll v, ll tl, ll tr, ll l, ll r, ll add) {
        if (l > r) return;

        if (l == tl && r == tr) {
            t[v] += add;
            lazy[v] += add;
        } else {
            push(v);

            ll tm = (tl + tr) / 2;

            update(v*2, tl, tm, l, min(r, tm), add);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, add);

            t[v] = min(t[v*2], t[v*2+1]);
        }
    }

    ll query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r) return LLONG_MAX;

        if (l == tl && r == tr) {
            return t[v];
        }

        push(v);

        ll tm = (tl + tr) / 2;

        return min(
            query(v*2,     tl, tm,     l, min(r, tm)),
            query(v*2 + 1, tm+1, tr,   max(l, tm+1), r)
        );
    }

    // ----- Métodos públicos -----

    void update(ll l, ll r, ll add) {
        update(1, 0, n-1, l, r, add);
    }

    ll query(ll l, ll r) {
        return query(1, 0, n-1, l, r);
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll q; cin >> q;

    queue<pair<bool, ll>> cola; 

    set<ll> A_set;
    vector<ll> A;
    unordered_map<ll, ll> idx_of;

    
    while(q--){
        string s; cin >> s;
        ll num = stoi(s.substr(1, (ll)s.size() - 1));
        
        if (s[0] == '+'){
            cola.push({true, num});

            if (A_set.find(num) == A_set.end()){
                A.push_back(num);
            }
            A_set.insert(num);
        }

        else cola.push({false, num});
    }

    sort(A.begin(), A.end());
    
    vector<ll> C(A.size() + 1, 0);
    rep(i, A.size()){
        C[i + 1] = A[i];
    }

    rep(i, (ll)A.size()){
        idx_of[A[i]] = i;
    }
    
    ST st(C);

    while(!cola.empty()){
        pair<bool, ll> query = cola.front(); cola.pop();
        
        if (query.first){
            // sumar 1 en rango [0, idx_of[q.second]]
            st.update(0, idx_of[query.second], 1);
        }
        else {
            // restar 1 en rango [0, idx_of[q.second]]
            st.update(0, idx_of[query.second], -1);
        }

        // hacer una query del minimo sobre el rango entero.

        cout << st.query(0, C.size() - 1) << " ";
    }
    cout << endl;

    return 0;
}