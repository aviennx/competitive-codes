#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

int gcd(int x, int y){
    if (x < y) swap(x, y);
    while (x > y && y != 0){
        x %= y;
        swap(x, y);
    }
    return x;
}

void solve(){
    int n, m;
    int ans = 0;
    cin >> n >> m;
    for(int A = 1; A * A <= n; A++){
        for(int B = 1; B * B <= m; B++){
            if(gcd(A,B) != 1)
                continue;
            int num = min(n / A, m / B);
            int den = A + B;
            ans += num / den;
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
