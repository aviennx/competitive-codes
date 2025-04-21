#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;



void solve(){
    string s;
    cin >> s;
    int n = s.size();
    if(n == 1){
        cout << "0\n";
        return;
    }
    int ans = 0;
    for(int len = 2; len <= n; len += 2){
        int vcount = 0;
        for(int i = 0; i < len / 2; i++)
            if(s[i] == s[i + len / 2] || s[i] == '?' || s[i + len / 2] == '?')
                vcount += 2;
        if(vcount == len){
            ans = len;
            continue;
        }
        for(int i = len; i < n; i++){
            if(s[i] == s[i - len / 2] || s[i] == '?' || s[i - len / 2] == '?')
                vcount += 2;
            if(s[i - len / 2] == s[i - len]  || s[i - len] == '?' || s[i - len / 2] == '?')
                vcount -= 2;
            if(vcount == len){
                ans = len;
                break;
            }
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
