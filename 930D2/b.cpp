#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 
long long mod = (int64_t)1e17 + 3;

void solve(){
    int n;
    cin >> n;
    string arr[2];

    for(int i = 0 ;i < 2; i++)
        cin >> arr[i];

    vector<vector<int>> dp(2,vector<int>(n,0));
    string best(1, arr[0][0]);
    bool up_path = true;
    for(int i = 1; i < n; i++){
        char up = arr[0][i], down= arr[1][i - 1];
        if(down < up){
            up_path = false;
        }
        if(up_path){
            best += min(up,down);
        }else
            best += down;
    }
    best += arr[1][n - 1];


    cout << best << '\n';

    for(int i = 0 ; i < n ; i++){
        if(arr[0][i] != best[i])
            break;
        dp[0][i] = 1;
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        if(arr[1][i] != best[i + 1])
            break;
        dp[1][i] = 1;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(dp[0][i] && dp[1][i])
            cnt++;

    cout << cnt << endl;

}


int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
