#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int l = 0, r = 0;
    while(l < n && r < m){
        if(s[l] == t[r]){
            l++;
            r++;
        }else if(s[l] =='?'){
            s[l] = t[r];
            l++;
            r++;
        }else
            l++;
    }
    for(auto& c : s)
        if(c == '?')
            c = 'a';
    if(r < m)
        cout << "NO\n";
    else{
        cout <<"YES\n";
        cout << s << '\n';
    }
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
