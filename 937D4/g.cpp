#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

string g[20] = {}, w[20] = {};
int mat[20][20];
int dp[(1 << 17)][20] = {};

void solve(){
    int n;
    cin >> n;
 
    for (int i = 0; i < n; i++)
        cin >> g[i] >> w[i];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = (g[i] == g[j] || w[i] == w[j]);

    for (int mask = 0; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            dp[mask][i] = 0;

    int ans = 0;

    for(int i = 0; i < n; i++)
        dp[(1 << i)][i] = 1;


    for(int i = 1; i < (1 << n); i++){
        for(int start = 0; start < n; start++){
            if( ((i >> start ) & 1) == 0)
                continue;
            for(int next = 0; next < n; next++){
                if((i >> next) & 1)
                    continue;
                int ni = i | (1 << next);
                if(mat[start][next])
                    dp[ni][next] = max(dp[ni][next], dp[i][start] + 1);
                dp[ni][start] = max(dp[ni][start], dp[i][start]);
            }
            ans = max(ans , dp[i][start]);
        }
    }
    cout << n - ans << '\n';
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
