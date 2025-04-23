#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

template <class T>
class segment_tree {
public:
    vector<T> tree;
    int n;

    segment_tree(int n = 0) : n(n) {
        tree.resize(4 * n, 0);
    }

    void update(int node, int start, int end, int idx, T val) {
        if (start == end) {
            tree[node] += val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    T query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) +
               query(2 * node + 1, mid + 1, end, l, r);
    }

    void Update(int idx, T val) {
        update(1, 0, n - 1, idx, val);
    }

    T Get(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<int> vals(n);
    vector<pair<int,int>> qr(q);
    vals[0] = 1;
    for(int& i : arr)
        cin >> i;
    for(auto& i : qr){
        cin >> i.first >> i.second;
        i.first--;
    }
    segment_tree<int> st(n + 1);
    st.Update(1, 1);
    for (int i = 1; i < n; i++) {
        int l = 1, r = n;
        int peak = n;
        while (l < r) {
            int mid =(l + r)/ 2;
            int chk = st.Get(1, mid) / mid;
            if ( chk < arr[i]) {
                peak = mid;
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        vals[i] = peak;
        st.Update(peak, 1);
    }
    for(int i = 0; i < q; i++)
        yesno(qr[i].second >= vals[qr[i].first]);
}

int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    //cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        //cout << test_case << " " << '\n';
        solve();
    }
    return 0;
}