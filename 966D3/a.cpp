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
    if(s.size() <= 2 || s[0] != '1' || s[1] != '0' || s[2] == '0'){
        cout << "NO\n";
        return;
    }
    int ind = 2;
    if(ind == -1){
        cout << "NO\n";
        return;
    }
    int v = stoi(s.substr(ind, n - ind));
    if(v >= 2){
        cout << "YES\n";

    }else
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
