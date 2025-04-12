#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m, a[N], d[N], k[N], par[N];
vector <pair <int, int>> s[11][11];

int find(int u) {
    if (par[u] < 0) return u;
    return par[u] = find(par[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < i; j++) {
            s[i][j].clear();
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> d[i] >> k[i];
        s[d[i]][a[i] % d[i]].push_back(make_pair(a[i], a[i] + k[i] * d[i]));
    }
    for (int i = 1; i <= n; i++) par[i] = -1;
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < i; j++) {
            sort(s[i][j].begin(), s[i][j].end());
            int p = 0;
            for (auto [l, r]: s[i][j]) {
                p = max(p, l);
                while (p < r) {
                    merge(p, p + i);
                    p += i;
                }
            }
        }
    }
    int c = 0;
    for (int i = 1; i <= n; i++) if (par[i] < 0) c++;
    cout << c << '\n';
}


int main() {
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
