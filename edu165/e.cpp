#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define int ll


#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

int t;

const int N = 3e5 + 20;
int n, a[N];
vector <int> vec[N];

struct node {
        int mn, val;
} seg[N << 2];

void build(int v = 1, int s = 0, int e = n) {
        seg[v].mn = n;
        seg[v].val = 0;

        if (e - s == 1) {
                seg[v].val = n;
                return;
        }

        int mid = (s + e) >> 1, lc = v << 1, rc = lc | 1;
        build(lc, s, mid);
        build(rc, mid, e);
}

void add(int l, int r, int val, int v = 1, int s = 0, int e = n) {
        if (r <= s || e <= l) return;
        if (l <= s && e <= r) {
                seg[v].val += val;
                seg[v].mn += val;
                return;
        }

        int mid = (s + e) >> 1, lc = v << 1, rc = lc | 1;
        add(l, r, val, lc, s, mid);
        add(l, r, val, rc, mid, e);

        seg[v].mn = min(seg[lc].mn, seg[rc].mn) + seg[v].val;
}

void solve(){
    cin >> n;
                for (int i = 0; i < n; i++) cin >> a[i], a[i]--;

                build();

                for (int i = 0; i < n; i++) vec[i].pb(-1);

                int ans = 0;
                for (int i = 0; i < n; i++) {
                        add(i, i + 1, -n);

                //      cout << "\t\t" << seg[1].mn << '\n';

                        add(vec[a[i]].back() + 1, i + 1, 1);
                        if (_sz(vec[a[i]]) > 1) {
                                add(vec[a[i]][_sz(vec[a[i]]) - 2] + 1, vec[a[i]].back() + 1, -1);
                        }
                        vec[a[i]].pb(i);

                //      cout << '\t' << i << ' ' << seg[1].mn << '\n';

                        if (seg[1].mn == 0) {
                                ans++;
                                add(0, i + 1, n);
                        }
                }

                cout << ans << '\n';

                for (int i = 0; i < n; i++) vec[i].clear();
}

int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
