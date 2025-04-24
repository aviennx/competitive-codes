#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "Alice\n" : "Bob\n")

const int N = 1e7 + 5;
int mx = 0;
int dp[N] = {};
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    int xr = 0;
    if(dp[0] == -1){
        for(int i = 0;i < N;i++) {
            if(i < 2){
                dp[i] = i;
                continue;
            }
            if(dp[i] != -1)
                continue;
            if(i == 2)
                mx = 0;
            else if(i == 3)
                mx = 2;
            else
                mx++;
            for(int j = i;j < N; j += i){
                if(dp[j] != -1)
                    continue;
                dp[j] = mx;
            }
        }
    }
    for(int i : arr)
        xr ^= dp[i];
    yesno(xr); 


}
int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    for(int i = 0 ; i <= 100; i++)
        cout << i << " : " << dp[i] << '\n';
    return 0;
}
