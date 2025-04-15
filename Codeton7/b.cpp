#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;
int n;
char s[N];
void solve(){
        cin >> n; s[n + 1] = 'C';
        for (int i = 1; i <= n; ++i) cin >> s[i];
        int pt1 = 1, pt2 = 1, ans = 0;
        while (s[pt1] == 'B') ++pt1, ++pt2;
        while (pt1 <= n) {
            int cntA = 0, cntB = 0;
            while (s[pt2] == 'A') ++pt2, ++cntA;
            while (s[pt2] == 'B') ++pt2, ++cntB;
            if (s[pt2 - 1] == 'B') ans += pt2 - pt1 - 1;
            if (cntB) pt1 = pt2 - 1;
            else break;
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
