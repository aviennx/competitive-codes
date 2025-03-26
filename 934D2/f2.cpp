#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n, k;
    int mod; cin >> n >> k >> mod;
    
    vector<vector<int>> dp(k + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= n + 2; i++){
        vector<vector<int>> ndp(k + 1, vector<int>(k + 1, 0));
        vector<vector<int>> pref(k + 1, vector<int>(k + 1, 0)); 
        
        for (int b = 0; b <= k; b++){
            pref[b][0] = dp[0][b];
            for (int a = 1; a <= k; a++){
                pref[b][a] = (pref[b][a - 1] + dp[a][b]) % mod;
            }
        }
        
        for (int b = 0; b <= k; b++){
            for (int c = 0; c <= k; c++){
                if (b > c){
                    ndp[b][c] = (pref[b][k] - pref[b][b - c - 1] + mod) % mod;
                } else {
                    ndp[b][c] = pref[b][k];
                }
            }
        }
        
        dp = ndp;
    }
    
    cout << dp[0][0] << "\n";


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