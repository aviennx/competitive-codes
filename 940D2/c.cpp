#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAX = 3e5 + 10;

#define ll long long

int dp[MAX + 5] = {};
void solve(){
    int n, k;
    cin >> n >> k;      
    for(int i=1; i<=k; i++){
        int x, y;
        cin >> x >> y;
        if(x == y)
            n -= 1;
        else
            n -= 2;
    }
    int ans = dp[n];
    cout << ans << endl;
}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= MAX; i++){
        dp[i] = dp[i - 1] + (i - 1) * 2 * dp[i - 2] % MOD;
        dp[i] %= MOD;
    }
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
