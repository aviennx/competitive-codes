#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")
const int N = 2e5 + 5;

vc<vc<int>> dp, nposi;
vc<int> a, b;
int n, m;

int calc(int pos, int k) {
    if(pos >= n)
        return 0;
    if(k > m)
        return LLONG_MAX;
    if(dp[pos][k] != -1)
        return dp[pos][k]; 
    int ans = LLONG_MAX;
    if(k < m) {
        int nc = calc(pos, k + 1);
        if(nc != LLONG_MAX) {
            ans = nc;
        }
    }
    int next_p = nposi[pos][k];
    if(next_p > pos) {
        int nc = calc(next_p, k);
        if(nc != LLONG_MAX && LLONG_MAX - nc >= m - k) {
            ans = min(ans, m - k + nc);
        }
    }
    return dp[pos][k] = ans;
}
void solve() {
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    for(int& i : a)
        cin >> i;
    for(int& i : b)
        cin >> i;
    dp.assign(n + 1, vc<int>(m + 1, -1));
    nposi.assign(n + 1, vc<int>(m + 1, n + 1));
    for(int k = 1; k <= m; k++) {
        int currans = 0;
        int j = n;
        for(int i = n; i >= 0; i--) {
            while(j > i && currans > b[k-1]) {
                currans -= a[j-1];
                j--;
            }
            nposi[i][k] = j;
            if(i > 0)
                currans += a[i-1];
        }
    }
    int ans = calc(0, 1);
    cout << (ans == LLONG_MAX ? -1 : ans) << "\n";
}
int32_t main() {
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for(int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}