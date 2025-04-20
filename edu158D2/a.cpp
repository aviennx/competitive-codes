 #include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    int ans = 2 * (x - arr.back()); 
    int prev = 0;
    for(int i : arr){
        ans = max(ans, i - prev);
        prev = i;
    }
    cout << ans << '\n';


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
