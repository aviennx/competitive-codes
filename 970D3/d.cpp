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
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    string s ;
    cin >> s;
    s = "?" + s;
    vector<int> ans(n + 1, 0), visited(n + 1, 0);
    vector<int> z;
    auto dfs = y_combinator([&](const auto &self,int node)->int{
        visited[node] = true;
        z.push_back(node);
        int x = 0;
        if (s[node] == '0') {
            x++;
        }
        int next_node = arr[node];
        if (!visited[next_node]) {
            x += self(next_node);
        }
        return x;
    });
    for(int i = 1; i <= n; i++){
        z.clear();
        int c = 0;
        if(!visited[i])
            c = dfs(i);
        for(int j : z)
            ans[j] = c;
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << '\n';
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
