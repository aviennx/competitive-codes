#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 
const int MAXN = 200005;

int n;
int a[MAXN];
int prv[MAXN],nxt[MAXN];
bool in[MAXN];

bool good(int i) {
    if (i < 1 || i > n) {
        return 0;
    }
    return a[prv[i]] == a[i] - 1 || a[nxt[i]] == a[i] - 1;
}
void solve(){
    cin >> n;
        priority_queue<pair<int, int>> pq;
        for (int i = 1; i <= n; i++) {
            prv[i] = i - 1;
            nxt[i] = i + 1;
            in[i] = 0;
            cin >> a[i];
        }
        a[n + 1] = a[0] = -2;
        for (int i = 1; i <= n; i++) {
            if (good(i)) {
                in[i] = 1;
                pq.push({a[i], i});
            }
        }
        while (!pq.empty()) {
            auto [_, i] = pq.top(); pq.pop();
            nxt[prv[i]] = nxt[i];
            prv[nxt[i]] = prv[i];
            if (!in[prv[i]] && good(prv[i])) {
                in[prv[i]]=1;
                pq.push({a[prv[i]], prv[i]});
            }
            if (!in[nxt[i]] && good(nxt[i])) {
                in[nxt[i]]=1;
                pq.push({a[nxt[i]], nxt[i]});
            }
        }
        int mn = n, bad = 0;
        for (int i = 1; i <= n; i++) {
            bad += !in[i];
            mn = min(a[i], mn);
        }
        if (bad == 1 && mn == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

}


int main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
