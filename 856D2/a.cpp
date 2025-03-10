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
        vector <string> long_subs;
        for(int i = 0; i < 2 * n - 2; i++){
            string s; 
            cin >> s;
            if((int)s.size() == n - 1){
                long_subs.push_back(s);
            }
        }
        reverse(long_subs[1].begin(), long_subs[1].end());
        if(long_subs[0] == long_subs[1]){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
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
