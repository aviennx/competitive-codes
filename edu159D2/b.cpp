#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n, p, l, t;
    cin >> n >> p >> l >> t;
    int c = (n + 6) / 7;
    int low = 0, high = n;
    int ans = n;
    while(low <= high){
        int k = (low + high) / 2;
        int val = k * l + min(c, 2 * k) * t;
        if(val >= p){
            ans = min(ans , k);
            high = k - 1;
        }else
            low = k + 1;
    }
    cout << n - ans << '\n';
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
