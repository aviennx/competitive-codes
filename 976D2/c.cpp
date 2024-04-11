#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;
void solve(){
    int a, b, c, d;
    cin >> b >> c >> d;
    a = 0;
    bool flag = 1;
    
    for(int bit = 0; bit < 63 ; bit++) { 
        int bi = (b >> bit & 1ll);
        int ci = (c >> bit & 1ll);
        int di = (d >> bit & 1ll);
        int ai = 0ll;
        if(di){
            if(!bi && ci)
                flag = 0;
            else if(!bi && !ci)
                a |= (1ll << bit);
        }else{
            if(bi && !ci)
                flag = 0;
            else if(bi && ci)
                a |= (1ll << bit);
        }
    }
    int val = (a | b) - (a & c);
    if(!flag || val != d){
        cout << -1 << '\n';
        return;
    }
    cout << a << '\n';
    return;
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