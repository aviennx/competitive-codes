#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int k, q;
    cin >> k >> q;
    vector<int> kick(k), query(q);
    int mn = INT_MAX;
    for(int& i : kick){
        cin >> i;
        mn = min(mn, i);
    }
    for(int& i : query){
        cin >> i;
        cout << min(mn - 1, i) << " ";
    }
    cout << '\n';

   


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
