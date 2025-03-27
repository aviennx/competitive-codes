#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")
 
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1;
    for (int k = n; k > 0; --k) {
        vector<char> t(n), end(n + 1);
        for (int i = 0; i < n; ++i) {
            t[i] = s[i] - '0';
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt -= end[i];
            t[i] ^= (cnt & 1);
            if (t[i] == 0) {
                if (i + k <= n) {
                    ++end[i + k];
                    ++cnt;
                    t[i] = 1;
                } else {
                    break;
                }
            }
        }
        if (*min_element(all(t)) == 1) {
            cout << k << '\n';
            return;
        }
    }
    cout << ans << '\n';
   


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
