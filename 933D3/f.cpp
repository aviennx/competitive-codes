#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define int long long
#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;


const int N = 2e5 + 5;


void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> d(m);
    rep(i, 0, m) cin >> d[i];
    vector<ll> f(k);
    rep(i, 0, k) cin >> f[i];

    vector<pair<ll, int>> gaps;
    rep(i, 1, n) {
        gaps.push_back({a[i] - a[i - 1], i});
    }
    sort(all(gaps));
    int i = gaps.back().second;
    ll L = a[i - 1], R = a[i];
    ll ans = gaps.back().first;
 
    sort(all(d));
    sort(all(f));
 
    for (ll D : d) {
        ll target = (L + R + 1) / 2 - D;
        auto it = lower_bound(all(f), target);
        if (it != f.end()) {
            ans = min(ans, max(R - D - *it, D + *it - L));
        }
        if (it != f.begin()) {
            it--;
            ans = min(ans, max(R - D - *it, D + *it - L));
        }
    }
 
    if (gaps.size() >= 2) {
        ans = max(ans, gaps[gaps.size() - 2].first);
    }
    cout << ans << '\n';

   


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
