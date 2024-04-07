#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

   
int dp[1005][105] = {};
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        for(int j = 0; j <= k; j++)
            dp[i][j] = 1e9;
    }
    for(int i = k; i >= 0; i--)
        dp[n][i] = 1e9;
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        int y = b[i];
        int mx = x + y;
        int curr_cost = 0;
        for(int j = 0; j <= mx && j <= k; j++){
            for(int prev = 0; prev + j <= k; prev++){
                dp[i + 1][prev + j] = min(dp[i + 1][prev + j], dp[i][prev] + curr_cost);
            }
            if(x <= y && x){
                curr_cost += x;
                y--;
            }else{
                curr_cost += y;
                x--;
            }
        }
    }
    cout << (dp[n][k] == 1e9 ? -1 : dp[n][k]) << '\n';
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
