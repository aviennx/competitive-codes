#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;


const int N = 2e5 + 5;

void solve(){
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    vector<vector<int>> adj(n + m);
    int tm = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v, --c;
        if (!mp.count(c)) mp[c] = tm++;
        adj[u].push_back(n + mp[c]);
        adj[v].push_back(n + mp[c]);
        adj[n + mp[c]].push_back(u);
        adj[n + mp[c]].push_back(v);
    }
    int st, end;
    cin >> st >> end;
    --st, --end;
    queue<int> q;
    q.push(st);
    vector<int> dis(n + m, -1);
    dis[st] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v: adj[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    int t = dis[end];
    cout << t / 2 << endl;

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
