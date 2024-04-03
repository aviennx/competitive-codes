#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
typedef long long ll;
const int N = 3e5 + 5;
const int lg = 20;
const int inf = LLONG_MAX;
int arr[N] = {};
int dp[22][N] = {};
vector<int> adj[N] = {};

void dfs(int curr, int prev){
    for(int i = 1; i <= lg; i++){
        dp[i][curr] = i * arr[curr];
    }
    for(int next: adj[curr]){
        if(next == prev)
            continue;
        dfs(next, curr);
        int min1 = inf, min2 = inf;
        for(int j = 1; j <= lg; j++){
            min2 = min(min2, dp[j][next]);
            if(min2 < min1)
                swap(min2, min1);
        }
        for(int j = 1; j <= lg; j++){
            int val = min1;
            if(dp[j][next] == min1)
                val = min2;
            dp[j][curr] += val;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    int ans =LLONG_MAX;
    for(int i = 1; i <= lg; i++)
        ans = min(ans, dp[i][1]);
    cout << ans << '\n';
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        arr[i] = 0;
        for(int j = 1; j <= lg; j++)
            dp[j][i] = 0;
    }
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
