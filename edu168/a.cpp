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
        map<char,int> cnt;
        int index = -1;
        for(int i = 0; i < n; i++){
            if(++cnt[s[i]] == 2){
                index = i;
                break;
            }
        }
        char d = s[0] + 1;
        string ans = "";
        bool done = 1;
        for (int i = 0; i + 1 < s.size(); i++) {
            ans += s[i];
            if (s[i] == s[i + 1] && done){
                ans += (s[i] == 'a' ? 'b' : 'a');
                done = 0;
            }
        }
        ans += s.back();
        if (done)
            ans += (s.back() == 'a' ? 'b' : 'a');
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
