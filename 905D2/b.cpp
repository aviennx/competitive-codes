#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 10001;
const ll D[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
 
void solve(){
    ll n, k;
    cin >> n >> k;
 
    vector <ll> a(n);
    ll odd = 0, p = 1;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        odd += (a[i] % 2);
        p *= a[i];
        p %= k;
    }
 
    ll x = INF;
    for (ll i = 0; i < n; i++) {
        ll v = (a[i] % k == 0 ? 0ll : k - (a[i] % k));
        x = min(v, x);
    }
 
    if (k == 4) {
        if (odd >= 2) x = min(x, 2ll);
        if (odd <= n - 1 && odd >= 1) x = min(x, 1ll);
    }
 
    cout << (p % k == 0 ? 0ll : x) << '\n';
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
