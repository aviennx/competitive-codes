#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define ll long long 
const int N = 2e5 + 5;

void solve(){
    int n, c;
    cin >> n >> c;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int odd = 0, even = 0;
    ll ans = 1ll * (c + 1) * (c + 2) / 2;
    for (int i = 0; i < n; i++) {
        ans -= s[i] / 2 + 1;
        ans -= c - s[i] + 1;
        if (s[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    ans += 1ll * even * (even + 1) / 2;
    ans += 1ll * odd * (odd + 1) / 2;
    cout << ans << "\n";
   


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
