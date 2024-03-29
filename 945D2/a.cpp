#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")




void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    int tmp = a;
    a = max(tmp, b);
    b = min(tmp, b);
    tmp = a;
    a = max(tmp, c);
    c = min(tmp, c);
    int ans = 0;
    while(a){
        if(b > c){
            if(b == 0)
                break;
            b--;
        }
        else{
            if(c == 0)
                break;
            c--;
        }
        a--;
        ans++;
    }
    int k = min(b, c);
    ans += k;
    b -= k;
    c -= k; 
    if(a){
        if(a % 2)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
        return;
    }
    if( b % 2 == 0 && c % 2 ==0){
        cout << ans << '\n';
    }
    else
        cout << -1 << '\n';
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
