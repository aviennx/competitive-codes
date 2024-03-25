#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> mp(n, 0);
    int rem = 0;
    for(int& i : arr){
        cin >> i;
        mp[i - 1]++;
    }
    int ans = 0, sec_ans = 0, common = 0;

    for(int i : mp){
        if(i == 2)
            ans++;
        else if(i == 0)
            sec_ans++;
        else
            common++;
    }
    if(ans > sec_ans){
        ans += common;
    }
    cout << ans << '\n';

   


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
