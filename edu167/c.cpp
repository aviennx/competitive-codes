#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int x = 0, y = 0, neg = 0, pos = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] > b[i]) {
        x += a[i];
      } else if (a[i] < b[i]) {
        y += b[i];
      } else {
        neg += (a[i] < 0);
        pos += (a[i] > 0);
      }
    }
    int ans = -1e9;
    for (int i = -neg; i <= pos; ++i)
      ans = max(ans, min(x + i, y + (pos - neg - i)));
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
