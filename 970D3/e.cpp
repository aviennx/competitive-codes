#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

void solve(){
    int n;
    string s;
    cin >> n >> s;
    int fo[26] = {}, fe[26] = {};
    if(n == 1){
        cout << 1 << '\n';
        return;
    }
    int x = 0, y = 0;
    for(int i = 0; i < n; i += 2){
        fe[s[i] - 'a']++;
    }
    for(int i = 1; i < n; i += 2){
        fo[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++)
        x = max(x, fe[i]), y = max(y, fo[i]);
    int ans = n - (x + y);
    if (n % 2 == 0) {
        cout << ans << '\n';
        return;
    }else
        fe[s.back() - 'a']--;
    x = 0, y = 0;
    for(int i = 0; i < 26; i++)
        x = max(x, fe[i]), y = max(y, fo[i]);
    ans = n - (x + y);
    int fo2[26] = {}, fe2[26] = {};
    for (int i = n - 2; i >= 0; i--) {
        if (i % 2 == 0) {
            fe[s[i] -'a']--;
            fe2[s[i + 1] -'a']++;
        } else {
            fo[s[i] -'a']--;
            fo2[s[i + 1] - 'a']++;
        }
        x = 0, y = 0;
        for(int i = 0; i < 26; i++){
            x = max(x, fe[i] + fe2[i]), y = max(y, fo[i] + fo2[i]);
        }
        ans = min(ans, n - (x + y));
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
