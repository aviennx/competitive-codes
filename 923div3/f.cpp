#include<bits/stdc++.h>
using namespace std;

//#define int long long  

#define ar array
#define ll long long 
const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
int global_t ;
int cas;
vector<int> adj[MAX_N];

int parents[MAX_N], size_[MAX_N];
int visited[MAX_N];

void init_dsu(int n){
    for(int i = 1; i <= n ; i++){
        size_[i] = 1;
        parents[i] = i;
    }
}

int _find(int u){
    while(u != parents[u])
        u = parents[u];
    return parents[u];
}

bool _union(int a, int b){
    int x = _find(a), y= _find(b);
    if(x == y)
        return false;
    if(size_[x] >= size_[y]){
        size_[x] += size_[y];
        parents[y] = x;
    }else{
        size_[y] += size_[x];
        parents[x] = y;
    }
    return true;
}

bool dfs( int curr, int end, int prev, int start , vector<int>& path){
    //cout << curr <<"....";
    visited[curr] = true;
    if(curr == start){
        path.push_back(curr);
        return true;
    }
    for(int next: adj[curr]){
        if(next == prev || next == end || visited[next])
            continue;
        if(dfs(next,end, curr, start,path)){
            path.push_back(curr);
            return true;
        }
    }
    return false;
}


void solve(){
    int n, m;
    cin >> n >> m;
    //if(global_t > 200 && cas > 10)
      //  cout << n << m << endl;

    init_dsu(n);

    memset(visited, 0 , (n+1)*sizeof(int));

    vector<array<int,3>> edges;

    int ans = INT_MAX;
    array<int,3> min_edge = {0,0,0};

    for(int i = 1; i <= n; i++)
        adj[i].clear();

    for(int i = 0; i < m; i++){
        int u ,v ,w;
        cin >> u >> v >> w;
        //if(global_t > 200 && cas > 10)
          //  cout << u << v << w << endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({w, u, v});
    }

    sort(edges.rbegin(), edges.rend());

    for(auto [w, u ,v] : edges){
        if(_union(u, v))
            continue;
        if(w < ans){
            ans = w;
            min_edge = {w, u, v};
        }
    }

    vector<int> path;

    //cout << min_edge[1] << "-" << min_edge[2]<<endl;
    dfs(min_edge[2], min_edge[2], min_edge[1], min_edge[1], path);
    //cout << endl;
    cout << ans << " " <<  path.size()  << endl;
    for(int i : path)
        cout << i << ' ';
    cout << endl;

    for(int i = 1; i <= n; i++)
        adj[i].clear();


}


int32_t main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    global_t = t;
    for (int test_case = 1; test_case <= t; test_case++) {
        //if(global_t > 200 && cas > 10){
            //cout << test_case << " is test " << endl;
        //}
        cas = test_case;

        solve();
    }
    return 0;
}
