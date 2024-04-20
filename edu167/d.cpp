#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
 
template<typename Tp>
inline void chmin (Tp &x, const Tp &y) { if (y < x) x = y; }
template<typename Tp>
inline void chmax (Tp &x, const Tp &y) { if (x < y) x = y; }
 
//const int N = 2e6 + 5;
 
const int maxn = 1e6 + 20;
const int maxa = 1e6 + 20;
int n, m, a[maxn], b[maxn];
int dp[maxa], num[maxa];
long long ans;
void solve(){
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &b[i]);
    }
    memset (num, 0x3f, sizeof (num));
    for (int i = 1; i <= n; ++i) {
        chmin (num[a[i]], a[i] - b[i]);
    }
    for (int i = 1; i < maxa; ++i) {
        chmin (num[i], num[i - 1]);
        if (num[i] <= i) {
            dp[i] = dp[i - num[i]] + 2;
        }
    }
    for (int i = 1, c; i <= m; ++i) {
        scanf ("%d", &c);
        if (c >= maxa) {
            int d = c - (maxa - 1);
            int v =( d  + num[maxa - 1])/ num[maxa - 1];
            ans += 2ll * v;
            c -= v * num[maxa - 1];
        }
        ans += dp[c];
    }
    printf ("%lld\n", ans);
   


}


int32_t main(){
    fast;
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    //cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
