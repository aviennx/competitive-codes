#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
const int N = 2e5 + 5;
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> h(n + 1, 0), h2(n + 1, 0), freq1(n + 1, 0), freq2(n + 1, 0);
    auto dfs = y_combinator([&](const auto &self,int u,int par, int val)->void{
            h[u] = val;
            h2[u] = val;
            for(auto &x:adj[u]){
                if(x == par)
                    continue;
                self(x,u,val + 1);
                //cout << val + 1 << " " << sz[x] << " : ";
                h2[u] = max(h2[u], h2[x]);
            }
    });
    dfs(1, 0 ,0);
    int prev = 0, next = n - 1;
    for(int i = 2; i <= n; i++){
        freq2[h2[i]]++;
        freq1[h[i]]++;
    }
    int ans = INT_MAX;
    for(int i = 1; i < n; i++){
        next -= freq1[i];
       // cout << prev << " - " << next << '\n';
        ans = min(ans, next + prev);
        prev += freq2[i];
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
        solve();
    }
    return 0;
}
