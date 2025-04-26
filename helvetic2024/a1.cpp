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
    int balance = 0;
    vector<vector<int>> v;
    for(int i = 0 ; i < n; i++){
        v.push_back({balance, s[i], i});
        if(s[i] == '(')
            balance++;
        else
            balance--;
    }
    sort(v.begin(), v.end(), [&](auto& v1, auto& v2){
        if(v1[0] != v2[0])
            return v1[0] < v2[0];
        else
            return v1[2] > v2[2];
    });
    string ans = "";
    for(auto& vec : v){
        char c = vec[1];
        ans += c;
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
