#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

      
int ask(int a,int b){
    int x;
    printf("? %d %d\n", a, b);
    cin >> x;
    fflush(stdout);
    return x;
}
void ret(vector<int>& ans, int n){
    cout << "! ";
    for(int i = 2; i <= n; i++)
        cout << i << " " << ans[i] << " ";
    cout << '\n';
    fflush(stdout);
 }
void solve(){
    int n;
    cin >> n;
    int root = 1;
    auto dfs1 = y_combinator([&](const auto &self,int u,int check)->void{
            int v = ask(u, check);
            if(v != u && v != check){
                if(parents[v] == -1)
                    self(u, v);
                self(v, check);
                return;           
            }
            parents[check] = u;
        });
    auto dfs2 = y_combinator([&](const auto &self,int curr,int prev, int d)->void{
            dist[curr] = d;
            for(int next : adj[curr])
                self(next, curr , d + 1);
        });
    for(int i = 2; i <= n; i++){
        if(parents[i] == -1)
            dfs1(root, i);
    }
    ret(parents, n);
}


int32_t main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
