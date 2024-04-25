#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define ll long long
const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    ll a = 1, b = 1, c = 1, d = 1;
        for (ll i = 1; i <= n; i++) {
            ll x, y; cin >> x >> y;
            if (x > 0) a = 0;
            if (x < 0) b = 0;
            if (y > 0) c = 0;
            if (y < 0) d = 0;
        }
        if (a + b + c + d == 0) cout << "NO\n";
        else cout << "YES\n" ;

   


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

