#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
typedef long long ll;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct Node {
    ll max_1, max_2, min_1, min_2;

    Node(ll max1, ll max2, ll min1, ll min2){
        max_1 = max1;
        max_2 = max2;
        min_1 = min1;
        min_2 = min2;
    }
};

template <typename MergeOperation>
struct SegmentTree{
    ll n;
    vector<Node> st;
    MergeOperation merge_function;
    Node neutral_operator;


    // Hacemos una lista de inicializacion en vez de funcion init normal
    void build(ll node, ll l, ll r, const vector<ll>& A){
        if (l == r) {
            st[node] = Node(A[l], -1e4, A[l], 1e4);
            return;
        }

        ll mid = (l + r) / 2;
        build(2 * node, l, mid, A);
        build(2 * node + 1, mid + 1, r, A);
        st[node] = merge_function(st[2 * node], st[2 * node + 1]);
    }
    
    void update(ll node, ll i, ll x, ll l, ll r){
        if (i < l || i > r) return;

        if (l == r) st[node] = Node(x, -1e4, x, 1e4);
        else {
            ll mid = (l + r) / 2;
            update(2 * node, i, x, l, mid);
            update(2 * node + 1, i, x, mid + 1, r);
            st[node] = merge_function(st[2 * node], st[2 * node + 1]);
        }
    }

    Node query(ll node, ll L, ll R, ll l, ll r){ // L, R rangos de la query
        if (R < l || L > r) return neutral_operator;
        if (L <= l && r <= R) return st[node];

        ll mid = (l + r) / 2;
        return merge_function(
            query(2 * node, L, R, l, mid),
            query(2 * node + 1, L, R, mid + 1, r)
        );
    }

public:
    SegmentTree(const vector<ll>& A, MergeOperation op, Node neutral) :
        n(A.size()), merge_function(op), neutral_operator(neutral) {
        st.assign(4 * n, neutral);
        build(1, 0, n - 1, A);
    }

    Node query(ll L, ll R) {
        return query(1, L, R, 0, n - 1);
    }
    void update(ll i, ll x) {
        return update(1, i, x, 0, n - 1);
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q; cin >> n >> q;
    vector<ll> A(n); 
    rep(i, n) cin >> A[i];

    auto merge_nodes = [](const Node& a, const Node& b){
        return Node(
            max(a.max_1, b.max_1), max(min(a.max_1, b.max_1), max(a.max_2, b.max_2)),
            min(a.min_1, b.min_1), min(max(a.min_1, b.min_1), min(a.min_2, b.min_2))
        );
    };

    SegmentTree ST(A, merge_nodes, Node(-1e4, -1e4, 1e4, 1e4));
    while(q--){
        ll L, R; cin >> L >> R;
        L--; R--;
        ll ans = A[L] * A[R];     
        
        Node nodo = ST.query(L + 1, R - 1);
        ll mult;
        if(ans > 0){
            mult = max(
                nodo.min_1 * nodo.min_2, // mas negativos 
                nodo.max_1 * nodo.max_2 // mas positivos
            );
        } else {
            mult = min(
                nodo.max_1 * nodo.min_1, // mas positivo, con el mas negativo
                min(
                    nodo.min_1 * nodo.min_2, // mas chico
                    nodo.max_1 * nodo.max_2
                )
            );
        }
        ans *= mult;
        cout << ans << "\n";
    }

    return 0;
}