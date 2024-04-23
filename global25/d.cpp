#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    
    if (n < k) {
            cout << "NO\n";
        } else if (n == k) {
            cout << "YES\n1\n1\n";
        } else if (n < 2 * k - 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n2\n" << n - k + 1 << " 1\n";
        }


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
