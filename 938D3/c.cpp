#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")
#define ll long long
const int N = 2e5 + 5;

void solve(){
    ll n, k;
        cin >> n >> k;
 
        vector<ll> a(n);
 
        for(ll &x : a) cin >> x;
 
        int l = 0, r = n-1, turn = 0;
 
        int ans = 0;
 
        while(l <= r){
            if(l == r){
                if(k < a[l]) break;
                ans++;
                break;
            }
            if(a[l] < a[r] or (a[l] == a[r] and turn == 0)){
                if(k < 2*a[l]-(turn == 0)) break;
                k -= 2*a[l]-(turn == 0);
                a[r] -= a[l] - (turn == 0);
                a[l] = 0;
                ans++;
                l++;
                turn = 1;
            } else {
                if(k < 2*a[r]-turn) break;
                k -= 2*a[r]-turn;
                a[l] -= a[r] - turn;
                a[r] = 0;
                ans++;
                r--;
                turn = 0;
            }
        }
 
        cout << ans << "\n";


}


int32_t main(){
    fast;=
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
