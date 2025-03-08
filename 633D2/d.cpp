#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;
int odd, even;
map<int,int> dist;
vector<int> parents;
vector<int> di;
void dfs(int curr, int prev, int d, vector<int> adj[]){
    di[curr] = d;
    for(int next : adj[curr]){
        if(next == prev)
            continue;
        dfs(next, curr, d + 1, adj);
    }
    if(adj[curr].size() == 1){
        dist[d]++;
        //cout << d << '\n';
        if(d % 2)
            odd++;
        else
            even++;
        parents[curr] = prev;
    }
}
void solve(){
    int n;
    odd = 0, even = 0;
    cin >> n;
    vector<int> adj[n];
    vector<int> indeg(n, 0);
    parents.resize(n, -1);
    di.resize(n, 0);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        indeg[u]++;
        indeg[v]++;
    }
    int min_ans = 1, max_ans = n - 1;
    int root = -1;
    for(int i = 0; i < n; i++)
        if(indeg[i] == 1){
            root = i;
            break;
        }
    dfs(root, -1, 0, adj);
    if(odd)
        min_ans = 3;
    map<int,int> same_parent;
    for(int i = 0; i < n; i++){
        //cout << parents[i] << " ";
        if(parents[i] == -1)
            continue;
        if(di[i] != 2)
            same_parent[parents[i]]++;
    }
    //cout << '\n';
    if(dist.count(2))
        max_ans -= dist[2];
    for(auto [p, cnt] : same_parent)
        max_ans -= (cnt - 1);
    cout << min_ans << " " << max_ans << '\n';
   


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
