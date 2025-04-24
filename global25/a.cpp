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
    int a = -1 ,b = -1, cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            cnt++;
            b = a;
            a = i;
        }
    }
    if(cnt % 2 || (cnt == 2 && abs(b - a) == 1))
        yesno(0);
    else
        yesno(1);
   


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
