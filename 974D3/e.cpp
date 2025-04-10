#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void search(int start, vector<int>& dist, vector<int>& flag, vector<vector<pair<int,int>>>& adj){
    priority_queue<vector<int>, vector<vector<int>> , greater<>> q;
    q.push({0, start, flag[start]});
    dist[start] = 0;
    while(!q.empty()){
        auto x = q.top();
        q.pop();
        int d = x[0];
        int i = x[1];
        int type = x[2];
        for(auto [next, d2] : adj[i]){
            if(type){
                int distance = d2 / 2 + d;
                if(distance < dist[next]){
                    q.push({distance, next, type || flag[next]});
                    dist[next] = distance;
                }
            }else{
                int distance = d2 + d;
                if(distance < dist[next]){
                    q.push({distance, next, type || flag[next]});
                    dist[next] = distance;
                }

            }
        }
    }

}

void solve(){
    int n, m, h ;
    cin >> n >> m >> h;
    vector<int> flag(n + 1, 0);
    for(int i = 0; i < h; i++){
        int x;
        cin >> x;
        flag[x] = 1;
    }
    vector<vector<pair<int,int>>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist1(n + 1, INT_MAX), distn(n + 1, INT_MAX);
    search(1, dist1, flag, adj);
    search(n, distn, flag, adj);
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++){
        ans = min(ans, max(dist1[i],distn[i]));
    }
    if(ans == INT_MAX)
        cout << -1 << '\n';
    else
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
