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
    if(n == 1){
        cout << "YES\n";
        return;
    }
    int c0 = 0;
    int c1 = 0;
    int index = 0;
    for(int i = 0; i < n; i++){
        while(i < n && s[i] == '0'){
            i++;
            c0++;
        }
        if(c0){
            break;
        }
    }
    int c = c0 + 2;
    int r = n / (c0 + 2);
    c0 = 0, c1 = 0;
    bool check = false;
    for(auto i : s){
        if(i == '0')
            c0++;
        else
            c1++;
    }
    for(int i = 1; i * i <= n; i++){
        if(n % i || (i != n / i))
            continue;
        if(c1 == 2 * (i + n / i - 2) && c0 == (n - c1))
            check = 1;
    }
    yesno(check);
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
