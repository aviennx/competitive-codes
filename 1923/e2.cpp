#include <bits/stdc++.h>                 

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

#define inp(v)     for(auto &x: v) cin>>x 

struct ap{
    int base , diff;
    ap(){
        base = 0, diff = 0;
    }
    ap(int b, int d){
        base = b;
        diff = d
    }
}

ap zero_ap = {0,0};

ap add(ap a, ap b){
    ap ans;
    ans.base = a.base + b.base;
    ans.diff = a.diff + b.diff;
    return ans;
}

int convert(ap x , int n){
    int ans = x.base;
    ans += (n-1) * n* x.diff / 2ll;
    return ans;
}

struct tdata {
    ll sum, setval, addval;
    bool lazyset;
    tdata() {
        sum = setval = addval = lazyset = 0;
    }
    tdata(ll val) {
        sum = val;
        setval = addval = lazyset = 0;
    }
    tdata(tdata l, tdata r) {
        sum = l.sum + r.sum; 
    }
};
 
int n, q, arr[MAX_N];
tdata st[4 * MAX_N];
 

void build(int node, int start, int end) {
    if (start == end) {
        st[node] = tdata(arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    st[node].sum = st[2 * node].sum + st[2 * node + 1].sum;
}
 
void down(int node, int start, int end) { 
    int mid = (start + end) / 2;
    if (st[node].lazyset) {
        st[2 * node] = st[2 * node + 1] = st[node];
        st[2 * node].sum = (st[node].setval + st[node].addval) * (mid - start + 1);
        st[2 * node + 1].sum = (st[node].setval + st[node].addval) * (end - mid);
    }
    else {
        st[2 * node].addval += st[node].addval;
        st[2 * node + 1].addval += st[node].addval;
        st[2 * node].sum += st[node].addval * (mid - start + 1);
        st[2 * node + 1].sum += st[node].addval * (end - mid);
    }
    st[node].addval = st[node].setval = st[node].lazyset = 0;
}

// t = 1 means range add update, t = 2 means range set update
void update(int node, int start, int end, int l, int r, ap val, int t) { 
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        if (t == 2) {
            st[node].setval = val;
            st[node].lazyset = 1;
            st[node].addval = 0;
            st[node].sum = val * (end - start + 1);
        }
        else {
            st[node].addval += val;
            st[node].sum += val * (end - start + 1);
        }
        return;
    }
    down(node, start, end);
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val, t);
    update(2 * node + 1, mid + 1, end, l, r, val, t);
    st[node].sum = st[2 * node].sum + st[2 * node + 1].sum;
}
 
tdata query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return tdata(0);
    if (l <= start && end <= r) return st[node];
    down(node, start, end);
    int mid = (start + end) / 2;
    return tdata(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}
 
 /*
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    while (q--) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 3) cout << query(1, 1, n, l, r).sum << "\n";
        else {
            int x; cin >> x;
            update(1, 1, n, l, r, x, t);
        }
    }
}

*/

void solve(){
    int n , m , q;
    cin >> n >> m >> q;
    int X[m], V[n+1];

    set<int> harbours;

    for(int i=0;i<m;i++)
    {
        cin>>X[i];
        harbours.insert(X[i]);
    }
    for(int i=0;i<m;i++)
    {
        int v;
        cin>>v;
        arr[X[i]] = v;
        V[X[i]] = v;
    }
    for(int i=1;i<=n;i++)
    {
        if(arr[i] == 0)
        arr[i] = arr[i-1];
    }
    int dist=0;
    for(int i=n;i>0;i--)
    {
        if(harbours.find(i) != harbours.end())
        dist=0;
        else
        dist++;
        arr[i] *= dist;
    }

    build(1, 1, n);

    while(q--){
        int type ;
        cin >> type;
        if(type == 1){
            int x, v;
            cin >> x >> v;
            V[x] = v;
            auto it = harbours.lower_bound(x);
            int next = *it;
            it--;
            int prev = *it;

            ap val = {0,0};
            update(1, 1, n, prev + 1, x,  )

            harbours.insert(x);
        }else{
            int l ,r;
            cin >> l >> r;

        }
    }








}


int32_t  main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
