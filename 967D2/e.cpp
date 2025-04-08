#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
int n, a[N], last[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last[a[i]] = i;
    }
    set <int> s;
    for (int i = 1; i <= n; i++) if (last[a[i]]) s.insert(last[a[i]]);
    int cnt = s.size();
    cout << cnt << '\n';
    multiset <int> val;
    for (int t = 1, l = 1, r = 0; t <= cnt; t++) {
        while (r < *s.begin()) {
            ++r;
            if (last[a[r]]) val.insert(a[r]);
        }
        int x;
        if (t & 1) {
            x = *val.rbegin();
        } else {
            x = *val.begin();
        }
        while (a[l] != x) {
            if (last[a[l]]) val.erase(val.find(a[l]));
            ++l;
        }
        while (true) {
            auto it = val.find(x);
            if (it == val.end()) break;
            val.erase(it);
        }
        cout << x << ' ';
        s.erase(last[a[l]]);
        ++l;
        last[x] = 0;
    }
    cout << '\n';
}

int32_t main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
