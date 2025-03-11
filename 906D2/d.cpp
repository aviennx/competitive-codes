#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

using i64 = long long;
using namespace std;
const int N = 5e5 + 7;
int T, n, C, p[N]; i64 a[N];
void solve () {
    cin >> n >> C;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    iota (p + 1, p + n + 1, 1);
    sort (p + 1, p + n + 1, [&] (const int &u, const int &v) {
        return 1ll * u * C - a[u] < 1ll * v * C - a[v];
    });
    i64 now = a[1];
    for (int i = 1, u; i <= n; i ++) {
        u = p[i];
        if (u == 1) continue;
        if (1ll * u * C > now + a[u])
            return cout << "No\n", void ();
        now += a[u];
    }
    return cout << "Yes\n", void ();
}


int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
