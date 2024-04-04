#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")


const int N = 500005;

int n, k, a[N];
int dp[N], b[N];

bool check(int med) {
    for (int i = 0; i < n; i++) {
        if (a[i] >= med) {
            b[i] = 1;
        } else {
            b[i] = -1;
        }
    }

    dp[0] = b[0];
    for (int i = 1; i < n; i++) {
        if (i%k == 0) {
            dp[i] = max(dp[i-k], b[i]);
        } else {
            dp[i] = dp[i-1] + b[i];
            if (i >= k) {
                dp[i] = max(dp[i], dp[i-k]);
            }
        }
    }

    return dp[n-1] > 0;
}
void solve(){
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int lo = 1, hi = 1e9;
        int ans = lo;
        while (lo < hi) {
            int mid = lo + hi >> 1;
            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        cout << ans << '\n';
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
