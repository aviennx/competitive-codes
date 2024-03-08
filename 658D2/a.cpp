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
    vector<int> a(n), b(m);
    unordered_map<int,int> mp;
    for(int& i : a){
        cin >> i;
        mp[i]++;
    }
    int ans = -1;
    for(int& i : b){
        cin >> i;
        if(mp.count(i)){
            ans = i;
        }
    }
    if(ans != -1){
        cout << "YES\n";
        cout << 1 << " " << ans << '\n';
    }
    else
    cout <<"NO\n";

   


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
