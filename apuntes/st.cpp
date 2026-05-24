#include<bits/stdc++.h>
using namespace std;

template <typename MergeOperation>
struct SegmentTree{
    int n;
    vector<int> st;
    MergeOperation merge_function;
    int neutral_operator;


    // Hacemos una lista de inicializacion en vez de funcion init normal
    void build(int node, int l, int r, const vector<int>& A){
        if (l == r) {
            st[node] = A[l];
            return;
        }

        int mid = (l + r) / 2;
        build(2 * node, l, mid, A);
        build(2 * node + 1, mid + 1, r, A);
        st[node] = merge_function(st[2 * node], st[2 * node + 1]);
    }
    
    void update(int node, int i, int x, int l, int r){
        if (i < l || i > r) return;

        if (l == r) st[node] = x;
        else {
            int mid = (l + r) / 2;
            update(2 * node, i, x, l, mid);
            update(2 * node + 1, i, x, mid + 1, r);
            st[node] = merge_function(st[2 * node], st[2 * node + 1]);
        }
    }

    int query(int node, int L, int R, int l, int r){ // L, R rangos de la query
        if (R < l || L > r) return neutral_operator;
        if (L <= l && r <= R) return st[node];

        int mid = (l + r) / 2;
        return merge_function(
            query(2 * node, L, R, l, mid),
            query(2 * node + 1, L, R, mid + 1, r)
        );
    }

public:
    SegmentTree(const vector<int>& A, MergeOperation op, int neutral) :
        n(A.size()), merge_function(op), neutral_operator(neutral) {
        st.assign(4 * n, neutral);
        build(1, 0, n - 1, A);
    }

    int query(int L, int R) {
        return query(1, L, R, 0, n - 1);
    }
    int update(int i, int x) {
        return update(1, i, x, 0, n - 1);
    }
};

int main(){
    auto max_merge = [](int a, int b) { return max(a, b); };
    auto min_merge = [](int a, int b) { return min(a, b); };


    vector<int> A = {1, 9, 3, 4, 8, 6, 7, 5, -1, 10};
    SegmentTree st_max(A, max_merge, 0);
    SegmentTree st_min(A, min_merge, INT_MAX);

    cout << st_max.query(0, 5) << " " << st_min.query(0, 5) << endl;
    return 0;
}