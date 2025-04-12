#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count; // Number of connected components

public:
    // Constructor to initialize parent, rank, and count
    UnionFind(int n) : parent(n), rank(n, 0), count(n) {
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find operation with path compression
    int findSet(int x) {
        while(x != parent[x])
            x = parent[x];
        return parent[x];
    }

    // Union operation with union by rank
    void unionSet(int x, int y) {
        int rootX = findSet(x);
        int rootY = findSet(y);

        if(rootX != rootY){
            // Union by rank
            if(rank[rootX] < rank[rootY]){
                parent[rootX] = rootY;
                rank[rootY] += rank[rootX];
            }
            else if(rank[rootX] > rank[rootY]){
                parent[rootY] = rootX;
                rank[rootX] += rank[rootY];
            }
            else{
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }
    }
    int getCount() const {
        return count - 1;
    }
};
vector<pair<int,int>> groups[11][11];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= 10; i++)
        for(int j = 0; j < i; j++)
            groups[i][j].clear();
    for(int i = 0; i < m; i++){
        int a, d, k;
        cin >> a >> d >> k;
        int at = d;
        int rem = a % d;
        groups[at][rem].push_back({a, a + d * k});
    }
    UnionFind uf(n + 1);
    for(int d = 1; d <= 10; d++){
        for(int rem = 0; rem < d; rem++){
            sort(groups[d][rem].begin(), groups[d][rem].end());
            int p = 0;
            for (auto [l, r]: groups[d][rem]) {
                p = max(p, l);
                while (p < r) {
                    uf.unionSet(p, p + d);
                    p += d;
                }
            }
        }
    }
    cout << uf.getCount() << '\n';

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