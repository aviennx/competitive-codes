#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int MAX_N = 2e5 + 1;
int n, q, arr[MAX_N], st[4 * MAX_N];
 
void build(int node, int start, int end) {
    if (start == end) {
        st[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    st[node] = min(st[2 * node], st[2 * node + 1]);
}
int query(int node, int start, int end, int l, int r, int md) {
    if (start > r || end < l) return 0;
    if (l <= start && end <= r) return st[node];
    int mid = (start + end) / 2;
    return min(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r)); 
}
 
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int k, u; cin >> k >> u;
            update(1, 1, n, k, u);
        }
        else {
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
}
void solve(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cout << n << " " << q << '\n';
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1];
        pref[i] += arr[i];
    }
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        cout << (pref[r] - pref[l]) % x << " ";
    }
}


int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    //cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
