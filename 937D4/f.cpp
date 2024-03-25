#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a + b + c == 0){
        cout << 0 << '\n';
        return;
    }
    if(c != a + 1){
        cout << -1 << '\n';
        return;
    }
    int leaves = 1;
    int ans = 0;
    while(a + b){
        ans++;
        int next = leaves;
        if(a){
            next += min(a, leaves);
            int temp = a;
            a -= min(a, leaves);
            leaves -= min(temp, leaves);
        }
        if(b && leaves){
            b -= min(b , leaves);
        }
        leaves = next;

    }
    cout << ans << '\n';
    return;


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
