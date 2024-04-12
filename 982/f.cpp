#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define vc vector
#define pii pair<int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 3e5 + 5;
const int INF = 1e17 + 7;

int n, m;
int pref[N], a[N], b[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    vc<vc<int>> dp(n + 1, vc<int>(m + 1, INF));
    dp[0][1] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] == INF) continue;
            if (j < m) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            }
            int target = pref[i] + b[j];
            int next_pos = upper_bound(pref + 1, pref + n + 1, target) - pref - 1;

            dp[next_pos][j] = min(dp[next_pos][j], dp[i][j] + m - j);
        }
    }

    // Find minimum total cost among all k values at position 'n'
    int ans = INF;
    for (int i = 1; i <= m; i++) {
        ans = min(ans, dp[n][i]);
    }

    // Output the result
    cout << (ans == INF ? -1 : ans) << "\n";
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}