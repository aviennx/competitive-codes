#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n; cin >> n;
    int mid = n / 2;
    vector<int> ans(n);
    if(n % 2 == 0){
        cout << -1 << '\n';
        return;
    }
    ans[mid] = 1;
    int curr = 2;
    for(int i = 1; i <= mid; i++){
        ans[mid + i] = curr++;
        ans[mid - i] = curr++;
    }
    for(int i : ans)
        cout << i << " ";
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
