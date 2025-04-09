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
    string s;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> s;
    vector<int> curr_w(n + 1, 0);
    vector<int> done(n + 1, 0);
    int root = 1;
    int seen = 0;
    map<int,int> freq;
    vector<int> marked(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int w = (s[i - 1] == '?') ? -1 : s[i - 1] - '0';
        curr_w[i] = w; 
        if(w == -1)
            marked[i] = true;
    }
    vector<int> leaf_vals;
    int ans = 0;
    int base = curr_w[1];
    auto dfs = y_combinator([&](const auto &self,int curr,int prev, int v, int tot)->void{
            if(done[curr])
                return;
            done[curr] = 1;
            bool check = false;
            for(auto &x : adj[curr]){
                if(x == prev || done[x]){
                    continue;
                }
                check = true;
                self(x, curr, curr_w[x], tot + curr_w[x]);
            }
            if(adj[curr].size() == 1)
                leaf_vals.push_back(tot);
            if(check == false){
                freq[v]++;
                return;
            }
            if(curr == root)
                return;
            if(marked[curr])
                seen++;
        });
    dfs(1, 0, curr_w[1], curr_w[1]);
    int a = freq.count(0) ? freq[0] : 0;
    int b = freq.count(1) ? freq[1] : 0;
    int c = freq.count(-1) ? freq[-1] : 0;
    int special_p = (c + seen % 2) / 2;
    if(base != -1){
        ans = (c + 1) / 2;
        cout << ans + (base ? a : b) << '\n';
        return;
    }
    if(a != b){
        int v = max(a, b);
        cout << v + c / 2 << '\n';
    }else
        cout << special_p + a << '\n';
        
if(w[1] == 0) ans = f[1] + (f[2] + 1) / 2;
    if(w[1] == 1) ans = f[0] + (f[2] + 1) / 2;
    if(w[1] == 2 && f[0] == f[1]) ans = f[1] + (f[2] + (cnt % 2)) / 2;
    if(w[1] == 2 && f[0] != f[1]) ans = max(f[0], f[1]) + f[2] / 2;
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
