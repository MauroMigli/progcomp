#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repk(i, k, n) for(ll i = k; i < n; i++)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


ll W, H;

struct Node {
    ll x;
    ll id;
    bool left;
    Node(ll X, ll ID, bool LEFT){
        x = X;
        id = ID;
        left = LEFT;
    }
};

ll f(ll x, ll y){
    if (y == 0) return x;
    else if (x == W) return W + y;
    else if (y == H) return 2 * W + H - x;
    else return 2 * W + 2 * H - y;
}

bool compare(const Node& a, const Node& b){
    return a.x < b.x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> W >> H;
    ll n; cin >> n;
    set<ll> bordes_x = {0, W};
    set<ll> bordes_y = {0, H};
    ll id = -1;
    
    
    vector<Node> recta;
    
    rep(i, n){
        ll x_1, y_1, x_2, y_2; cin >> x_1 >> y_1 >> x_2 >> y_2;
        ll l = min(f(x_1, y_1), f(x_2, y_2));
        ll r = max(f(x_1, y_1), f(x_2, y_2));
        
        if ((bordes_x.count(x_1) || bordes_y.count(y_1)) && (bordes_x.count(x_2) || bordes_y.count(y_2))){
            id++;
            recta.push_back(Node(l, id, true));
            recta.push_back(Node(r, id, false));
        }
    }
    sort(recta.begin(), recta.end(), compare);
    
    stack<ll> st;
    rep(i, recta.size()){
        if (recta[i].left){
            st.push(recta[i].id);
        } else {
            if (recta[i].id == st.top()){
                st.pop();
            } else {
                cout << 'N' << endl;
                return 0;
            }
        }
    }
    cout << 'Y' << endl;
    
    return 0;
}