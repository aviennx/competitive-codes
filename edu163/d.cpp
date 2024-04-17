#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;
const int maxN = 5005;
const int mod = 998244353;

int arr[maxN] = {};
void solve(){
    int n;
    cin >> n;
    int tot = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        tot += arr[i];
    }
    sort(arr + 1, arr + n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(tot + 1, 0));
    dp[0][0] = 1;
    long long ans = 0;
    int so_far = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= so_far; j++){
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            dp[i][j + arr[i]] = (dp[i][j + arr[i]] + dp[i - 1][j]) % mod;
        }
        for(int j = 0; j <= so_far; j++){
            if(arr[i] >= j)
                ans = (ans + 1ll * dp[i - 1][j] * arr[i] % mod) % mod;
            else
                ans = (ans + dp[i - 1][j] * 1ll *((j + arr[i] + 1) / 2)) % mod;
        }
        so_far += arr[i];
    }
    cout << ans % mod << '\n';


}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    //cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
