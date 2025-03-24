#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define ll long long

const int N = 2e5 + 5;

void solve(){
        ll n, m;
        cin >> n >> m;
        
        ll hi = 0, sec_hi = 0;
        for (ll p = (1LL<<62); p > 0; p >>= 1) {
            if (p & n) {
                if (!hi) hi = p;
                else if (!sec_hi) sec_hi = p;
            }
        }
        bool flag = (sec_hi && ((m & hi) || (m <= sec_h)));
        if (!flag) {
            cout << -1 << '\n';
            return;
        }
        vector<ll> ans = {n, m};
        if (!(m & hi) && !(m & sec_hi)) ans = {n, m^sec_hi, m};
        
        cout << (ll)ans.size()-1 << '\n';
        for (auto &x: ans) cout << x << ' ';
        cout << '\n';
   


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
