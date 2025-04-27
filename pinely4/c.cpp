#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define ll long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
class DSU {

public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;  
        }
    }

    int find(int x) {
        return (x == parent[x]) ? x : (parent[x] = find(parent[x]));
    }

    int getSize(int x) {
        x = find(x);
        return size[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false; 
        }
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];

        return true;
    }
};


ll minimumSum(int n,vector<vector<int>>& edges) {
    ll ans = 0;

    DSU dsu(n);
    sort(edges.rbegin(), edges.rend());
    for (int i = n - 2; i >= 0; --i) {
        int w = edges[i][0]; 
        int u = edges[i][1];  
        int v = edges[i][2]; 
        //cout << w << " " << u << ": "<<dsu.getSize(u) << " " << v << ": "<< dsu.getSize(v) << '\n';
        ans += w * 1ll * dsu.getSize(u) * 1ll * dsu.getSize(v);
        ans %= mod;
        dsu.unite(u, v);
    }

    return ans;
}
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> edges;
    for(int i =0 ; i < n - 1; i++){
        int u , v , w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges.push_back({w, u , v});
    }
    cout << minimumSum(n , edges) << '\n';
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
