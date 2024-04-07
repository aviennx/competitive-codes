#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
        }
        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.emplace(0);
        dist[0] = 0;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            for (int y : adj[x]) {
                if (dist[y] == -1) {
                    dist[y] = dist[x] + 1;
                    q.push(y);
                }
            }
            if (x + 1 < n && dist[x + 1] == -1) {
                dist[x + 1] = dist[x] + 1;
                q.push(x + 1);
            }
        }
 
        vector<int> marked(n + 1);
        for (int i = 0; i < n - 1; i++) {
            for (int j : adj[i]) {
                if (j - i - 1<= dist[i] + 1 || j <= i)
                    continue;
                marked[i + 1]++;
                marked[j - (dist[i] + 1)]--;
            }
        }
        vector<int> ans(n - 1);
        for (int i = 0; i < n; i++)
            marked[i + 1] += marked[i];
        for (int i = 0; i < n - 1; i++)
            ans[i] = (marked[i] == 0);
        for(int i : ans)
            cout << i ;
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
