#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "Ron\n" : "Hermione\n")

const int N = 2e5 + 5;
/*
onst int N = 2e5 + 5;
vi g[N];
int cnt_bad[N];
 
void dfs(int v, int p) {
    cnt_bad[v] = 0;
    for(auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        cnt_bad[v] += (int)(cnt_bad[u] == 0);
    }
}
 
int ans[N];
 
void recalc(int v, int p) {
    ans[v] = (cnt_bad[v] > 0);
 
    for(auto &u : g[v]) {
        if (u == p) continue;
        cnt_bad[v] -= (int)(cnt_bad[u] == 0);
        cnt_bad[u] += (int)(cnt_bad[v] == 0);
        recalc(u, v);
        cnt_bad[u] -= (int)(cnt_bad[v] == 0);
        cnt_bad[v] += (int)(cnt_bad[u] == 0);
    }
}
 
void solve() {
    int n, t; cin >> n >> t;
    rep(_, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    recalc(1, -1);
    rep(_, t) {
        int v; cin >> v;
        cout << (ans[v] ? "Ron\n" : "Hermione\n");
    }
}
 
*/


vector<vector<int>> dist;
void dfs(int curr, int prev, int control, vector<int> adj[]){
    bool flag = true;
    for(int next : adj[curr]){
        if(next == prev)
            continue;
        dfs(next, curr, control ^ 1, adj);
        dist[curr][control] |= !dist[next][control ^ 1];
        flag = false;
    }
    if(flag)
        dist[curr][control] = 0;
}
void solve(){
    int n, t;
    cin >> n >> t;
    vector<int> adj[n] = {};
    dist.resize(n, vector<int> (2));

    vector<int> inc(n, 0);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        inc[u]++;
        inc[v]++;
    }
    vector<int> leaves;
    for(int i = 0; i < n; i++){
        if(inc[i] != 1)
            continue;
        leaves.push_back(i);
    }
    vector<int> init_stones(t);
    for(int& i : init_stones){
        cin >> i;
        i--;
    }
    dfs(init_stones[0], -1, 1, adj);
    for(int i : init_stones){
        if(dist[init_stones[i]][1] == 1)
            yesno(1);
        else
            yesno(0);
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
