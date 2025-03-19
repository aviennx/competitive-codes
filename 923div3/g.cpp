#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int& i : arr)
        cin >> i;

    int dp[n+1][3];

    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 3; j++)
            dp[i][j] = 101;

    dp[0][0] = 100, dp[0][1] = 1, dp[0][2] = 1;

    for(int i = 1; i < n; i++){

        for(int j = 0; j < 3; j++)
            dp[i][2] = min(dp[i][2], 1 + dp[i - 1][j]);
        for(int j = 0; j < i ; j++){
            if(j + arr[j] - 1 >= i - 1)
                dp[i][2] = min(dp[i][2], 1 + dp[j][2]);
        }
        

        for(int j = max(0, i - arr[i]); j < i; j++){
            dp[i][1] = min(dp[i][1], 1 + dp[j][0]);
            dp[i][1] = min(dp[i][1], 1 + dp[j][1]);
            dp[i][1] = min(dp[i][1], 1 + dp[j][2]);
        }
        for(int j = 0; j < i ; j++){
            if(j + arr[j] - 1 >= i - arr[i])
                dp[i][1] = min(dp[i][1], 1 + dp[j][2]);
        }

        for(int j = i - 1; j >= 0; j--){
            if(j + arr[j] - 1 >= i)
                dp[i][0] = min(dp[i][0] , dp[j][2]);
        }

         for(j=0;j<i;j++){
                    int last = min(j+a[j]-1, n-1);
                    int back = Math.max(0, i-a[i]);
                    if(last<=i||back>=j)
                        continue;
                    int min_back = 500;
                    for(int k=back;k<=j-1;k++){
                        min_back = Math.min(dp[k][0], min_back);
                        min_back = Math.min(dp[k][1], min_back);
                        min_back = Math.min(dp[k][2], min_back);
                    }
                    for(int k=i+1;k<=last;k++)
                        dp[k][0] = Math.min(dp[k][0], min_back + 2);
                }
    }
    int ans = 101;
    for(int j = 0; j < 3; j++)
        ans = min(dp[n - 1][j], ans);

    cout << ans << endl;


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

