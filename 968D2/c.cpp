#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> pref(n , vector<int>(26, 0));
    for(int i = 0; i < n; i++){
        if(i){
            for(int j = 0; j < 26; j++)
                pref[i][j] += pref[i - 1][j];
        }
        int c = s[i] - 'a';
        pref[i][c]++;
    }
    queue<pair<char,int>> pq;
    string ans = "";
    for(int i = 0; i < 26; i++){
        if(pref[n - 1][i])
            pq.push({'a' + i, pref[n - 1][i]});
    }
    for(int i = 0; i < n; i++){
        if(pq.empty())
            break;
        auto [v , cnt] = pq.front();
        pq.pop();
        if(cnt == 0){
            continue;
        }
        if(cnt > 1){
            pq.push({v, cnt - 1});
        }
        ans += v;
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
