#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = 'L' + s;
    s += 'L';
    int swim = 0;
    int curr = 0;
    while(curr <= n){
        if(s[curr] == 'C')
            break;
        if(s[curr] == 'W'){
            swim++;
            curr++;
            continue;
        }
        bool jump = false;
        for(int j = min(n + 1, curr + m); j > curr; j--){
            if(s[j] == 'L'){
                curr = j;
                jump = true;
                break;
            }
        }
        if(jump)
            continue;
        for(int j = min(n + 1, curr + m); j > curr; j--){
            if(s[j] == 'W'){
                curr = j;
                jump = true;
                break;
            }
        }
        if(!jump)
            break;
    }
    if(swim <= k && curr > n)
        cout << "YES\n";
    else
        cout << "NO\n";

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
