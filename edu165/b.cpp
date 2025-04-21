#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    string s; 
    cin >> s;
    int n = s.size();
    int ans = 0, start = 0;
    for(int i = 0; i<n; i++){
        if(s[i]=='1')
            continue;
        if(i > start)
            ans += i - start + 1;
        start++;
    }
    cout << ans << endl;

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
