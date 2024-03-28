#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")


void solve(){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 1 ; i <= m ; i++){
        ans += (i + n) / (i * i);
        ans -= i / (i * i);
    }
    cout << ans << "\n";
}


int32_t main(){
    fast;
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
