#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

using namespace std;
const int maxN = 300005;
const int MAXV = 1e15 + 1;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    vector<vector<int>> dp(n + 1, vector<int> (k + 1, MAXV));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int prev = 0; prev <= k; prev++){
            int curr_min = arr[i];
            for(int next = 0; next + prev <= k && i + next + 1 <= n; next++){
                curr_min = min(curr_min , arr[i + next]);
                dp[i + next + 1][prev + next] = min(dp[i + next + 1][next + prev], dp[i][prev] + (next + 1) * curr_min);
            }
        }
    }
    int ans = LLONG_MAX;
    for(int i = 0; i <= k; i++)
        ans = min(ans, dp[n][i]);
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
