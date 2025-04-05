#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, s, m;
    cin >> n >> s >> m;
    int prev = 0;
    int next = 0;
    bool ans = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(x - prev >= s){
            ans = 1;
        }
        prev = y;
    }
    ans |= (m - prev >= s);
    yesno(ans) ;
   


}


int32_t main(){
    fast;
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
