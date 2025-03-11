#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool t_valid = true;
    for(int i = 0; i < m - 1; i++)
        if(t[i] == t[i + 1])
            t_valid = false;
    for(int i = 0 ; i < n - 1; i ++){
        if(s[i] == s[i + 1]){
            if(!t_valid || t.back() == s[i + 1] || t[0] == s[i]){
                yesno(0);
                return;
            }
        }
    }
    yesno(1);
    return;
   


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
