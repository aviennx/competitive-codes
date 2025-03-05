#include <bits/stdc++.h>
using namespace std; 

#define ll long long

void solve(){
    int n, q;
    cin >> n >> q;

    ll dp[n + 1] = {};
    int lstAdd[n + 1] = {};

    for (int i = 1; i <= n; i++){
        int a, v; 
        cin >> a >> v;

        if (a == 1){
            lstAdd[i] = v;
            dp[i] = dp[i - 1] + 1;
        }
        else{
            lstAdd[i] = lstAdd[i - 1];
            dp[i] = ((v + 1) > 2e18 / dp[i - 1]) ? (ll)2e18 : dp[i - 1] * (v + 1);
        }
    }
    while (q--){
        ll k; 
        cin >> k;

        while (true){
            int pos = lower_bound(dp + 1, dp + n + 1, k) - dp;
            
            if (dp[pos] == k){
                cout<<lstAdd[pos]<<" \n"[q == 0];
                break;
            }
            if (k % dp[pos - 1] == 0){
                cout<<lstAdd[pos - 1]<<" \n"[q == 0];
                break;
            }
            k %= dp[pos - 1];
        }
    }
}


int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        //cout << "test_case " << test_case <<endl;
        solve();
        //cout <<" _-------------_ " << endl;
    }
    return 0;
}
