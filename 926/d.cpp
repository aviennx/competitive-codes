#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

#define ar array
#define int long long
#define ll long long
const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

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
void update(int node, int start, int end, int l, int r, ll val, int t) { 
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
 
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    build(1, 1, n);
    while (q--) {
        int index ;
        cin >> index;
        index++;
        int val = query(1, 1, n, index, index).sum;
        cout << "val = " << val << endl;
        update(1, 1, n, index, index, 0, 2);
        int repeat = val / n;
        update(1,1,n,1,n,repeat,1);
        int rem = val % n;
        if(rem == 0)
            continue;
        int r = min(n - index, rem);
        rem -= r;
        if(r)
            update(1,1,n,index + 1,index+r,1,1);
        if(rem)
            update(1,1,n,1,rem,1,1);
        //if (t == 3) cout << query(1, 1, n, l, r).sum << "\n";
        //else {
          //  int x; cin >> x;
          //  update(1, 1, n, l, r, x, t);
        //}
    }
    for(int i = 1; i <=n ; i++){
        cout << query(1, 1, n, i, i).sum << " ";
    }
    cout << "\n";
}


int32_t main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    //cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        cout << test_case << " is test \n";
        solve();
    }
    return 0;
}
