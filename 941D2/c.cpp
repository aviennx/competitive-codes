#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "Alice\n" : "Bob\n")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());
    unordered_map<int,int> f;
    for(int i :arr)
        f[i]++;
    int cnt = f.size();
    int vals;
    vector<int>::iterator ip;
    ip = std::unique(arr.begin(), arr.end());
    arr.resize(std::distance(arr.begin(), ip));
    //for(int i : arr)
    //    cout << i << " ";
    vector<int> diff;
    diff.push_back(arr[0]);
    for(int i=1; i< (int)arr.size(); i++)
        diff.push_back(arr[i] - arr[i-1]);
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = 1;
    for(int i=1; i <= diff.size(); i++){
        dp[i][1] = dp[i-1][0];
        dp[i][0] = (dp[i-1][1] && diff[i-1] == 1) || (dp[i-1][0] && diff[i-1] > 1);
    }
    int last = diff.size();
    if(dp[last][1])
        yesno(1);
    else 
        yesno(0);





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
