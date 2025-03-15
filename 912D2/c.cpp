#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    vector<int> suf(n);
    int ans = 0;
    for(int i = n - 1; i >= 1; i--){
        if(i + 1 < n)
            suf[i] = suf[i + 1];
        suf[i] += arr[i];
        if(suf[i] > 0)
            ans += suf[i];
    }
    ans += ((n > 1 ? suf[1] : 0 ) + arr[0]);
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
