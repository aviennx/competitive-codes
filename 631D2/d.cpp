#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int d, m;
    cin >> d >> m;
    int ans = 1;
    for(int i = 0; i < 31; i++){
        if(d < (1 << i))
            break;
        ans = ans * (min((1ll << (i + 1) ) - 1, d) - (1ll << i) + 2) % m;
    }
    ans--;
    if(ans < 0)
        ans += m;
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
