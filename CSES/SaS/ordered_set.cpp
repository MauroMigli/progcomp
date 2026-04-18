#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define rep(i, n) for(int i = 0; i < n; i++)

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

int main(){
    int n, k; cin >> n >> k;
    ordered_set s;
    rep(i, n) s.insert(i + 1);

    int j = 0;
    rep(i, n){
        j = (j + k) % (int)s.size();
        int valor = *s.find_by_order(j);
        cout << valor << " ";
        s.erase(valor);
    }
    cout << endl;
    return 0;
}