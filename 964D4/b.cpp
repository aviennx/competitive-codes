#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;
int f(int a,int b){
    if (a > b) return 1;
    if (a == b) return 0;
    if (a < b) return -1;
    return 0;
}
void solve(){
    int a , b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    if (f(a, c) + f(b, d) > 0)
        ans += 1;
    if (f(a, d) + f(b, c) > 0)
        ans += 1;
    if (f(b, c) + f(a, d) > 0)
        ans += 1;
    if (f(b, d) + f(a, c) > 0)
        ans += 1;


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
