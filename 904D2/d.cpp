#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;
bool MemoryST;
const int N = 1e6 + 5;
const int mod = 998244353;
int n, a[N], f[N];
bool flag[N];
void solve() {
    cin >> n;
    For (i, 1, n) a[i] = 0, flag[i] = 0;
    For (i, 1, n) {
        int x; cin >> x; a[x]++;
    }
    rep (i, n, 1) {
        f[i] = 0;
        for (int j = i; j <= n; j += i) f[i] += a[j];
        f[i] = (f[i] - 1) * f[i] / 2;
        for (int j = 2 * i; j <= n; j += i) f[i] -= f[j];
    }
    int ans = 0;
    For (i, 1, n) {
        if (a[i]) {
            for (int j = i; j <= n; j += i) flag[j] = 1;
        }
    }
    For (i, 1, n)
        if (!flag[i]) ans += f[i];
    cout << ans << endl;
    return;
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
