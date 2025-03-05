#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<vector<long long>>dp(n + 1,vector<long long>(k + 1));
    for(int i = 1;i <= k;++i)
        dp[0][i] = 1;
    
    for(long long sum = 1 ; sum <= n ; sum++){
        for(long long curr = 1; curr <= k ; curr++){
            for(long long prev = 1; curr*prev <= sum && curr + prev - 1 <= k ; prev ++){
                dp[sum][curr] = (dp[sum][curr] + dp[sum - curr*prev][prev] ) % mod;
            }
        }
    }

    long long ans = 0;
    for(int i = 1;i <= k;++i)   ans = (ans + dp[n][i]) % mod;
    cout<<ans<<'\n';
}
int main()
{
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
