#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int x, y, n;
    cin >> x >> y >> n;
    if(n % 2){
        cout << x << " " << y << '\n';
        n--;
        for(int i = 1; i <= n; i += 2){
        cout << x + i << " " << y << '\n';
        cout << x - i << " " << y << '\n';
     }
     return;
    }
    for(int i = 1; i <= n; i += 2){
        cout << x + i << " " << y << '\n';
        cout << x - i << " " << y << '\n';
     }
   


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
