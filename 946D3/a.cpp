#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int x, y;
    cin >> x >> y;
    int ans = 0;
    while(x || y){
        ans++;
        int curr = 15;
        if(y){
            curr -= min(8ll, y * 4);
            y -= min(2ll, y);
        }
        if(x){
            int temp = curr;
            curr -= min(temp, x);
            x -= min(temp, x);
        }
    }
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
