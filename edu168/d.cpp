#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;
int n;
vector<int> adj[N] = {};
int a[N] = {};
int b[N] = {};
int dis[N] = {};
int par[N] = {};
int mod = 1e9;
void refix(int n){
    for (int i = 0; i < n; i++) {
         b[i] = a[i];
    }
}
void dfs(int curr, int prev, int sum){
    par[curr]= prev;
    b[curr] -= sum;
    sum += max(0ll, 0ll - b[curr]);
    sum = min(sum, mod);
    for (int next : adj[curr]){
        dis[next]=dis[curr]+1;
        dfs(next,curr, sum);
    }
}
void solve(){
    cin >> n;
    mod *= n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        adj[i].clear();
    for(int i = 0; i < n; i++){
        dis[i] = 0;
    }
    vector<int> indeg(n, 0);
    int ans = a[0];
    int l = a[0];
    int r = l + 1e9;
    for (int i = 1; i < n ; i++) {
        int u, v;
        cin >> u;
        u--;
        v = i;
        par[u] = v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    while (l < r) {
        refix(n);
        int mid = (l + r + 1 )/ 2;
        b[0] =  (l + r + 1 )/ 2;
        dfs(0, -1 ,b[0] - a[0]);
        bool check = 0;
        for (int i = 0; i < n; i++) {
            if (adj[i].empty() && b[i] < 0){
                check = 1;
                break;
            }
        }
        if ( !check ) {
            l = mid;
            ans = l;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        mod = 1e9;
        solve();
    }
    return 0;
}
