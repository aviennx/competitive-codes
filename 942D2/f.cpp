#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1;
    vector<int> cnt(26,0);
    cnt[s[0] - 'a']++;
    for(int i = 1; i < n; i++){
        int x = s[i - 1] - 'a';
        int y = s[i] - 'a';
        cnt[x] = 1;
        cnt[y] = 1;
        ans += accumulate(cnt.begin() , cnt.end() ,0);
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
