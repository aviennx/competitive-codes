// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "bits/stdc++.h"
using namespace std;
using ll = long long int;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1005;
const ll inf = 1e18;
ll dp[N][N][4];
int a[N][N], mark[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    for (int i = 0; i < N; ++i) for (int x = 0; x < 4; ++x)
        dp[0][i][x] = dp[i][0][x] = inf;

    int t; cin >> t;
    while (t--) {
        ll n, m, k; cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> a[i][j];
        for (int i = 1; i <= n+1; ++i) {
            string s;
            if (i <= n) cin >> s;
            else s = string(m, '0');
            for (int j = 1; j <= m; ++j) mark[i][j] = s[j-1] == '1';
            mark[i][m+1] = 0;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                for (int x = 0; x < 4; ++x)
                    dp[i][j][x] = inf;

        dp[1][1][0] = 0;
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
            if (i == 1 and j == 1) continue;

            ll add = k*mark[i+1][j] + k*mark[i][j+1] + a[i][j]; // Always taken

            // From left -> either 0 or 2
            if (mark[i-1][j+1]) dp[i][j][2] = min(dp[i][j-1][0] + add, dp[i][j-1][2] + add + k);
            else dp[i][j][0] = min(dp[i][j-1][0] + add, dp[i][j-1][2] + add + k);

            // From up -> either 0 or 1
            if (mark[i+1][j-1]) dp[i][j][1] = min(dp[i-1][j][0] + add, dp[i-1][j][1] + add + k);
            else dp[i][j][0] = min(dp[i][j][0], min(dp[i-1][j][0] + add, dp[i-1][j][1] + add + k));
        }
        cout << dp[n][m][0] << '\n';
    }
}