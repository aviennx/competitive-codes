#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;



void debug2D(vector<vector<int>>& arr){
    int N = arr.size(), M = arr[0].size();
    cout << "------------------------" << endl;
    cout << "debugging array of size N = " << N << " and M = " << M << endl;

    for(int i = 0; i < M ;i++){
        for(int j : arr[i])
            cout << j << " ";
        cout << endl;
    } 

    cout << "------------------------" << endl;
}

void solve(){

    int n, k;
    cin >> n >> k;
 
    int A[n + 1][n + 1];
 
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            cin >> A[i][j];
    
    vector<int> dp[n + 1];
    dp[0] = {0};
 
    for (int i = 1; i <= n; i++){
        priority_queue<array<int, 3>> pq;
        pq.push({dp[i - 1][0], i - 1, 0});
        for (int j = i - 2; j >= -1; j--){
            pq.push({(j < 0 ? 0 : dp[j][0]) + A[j + 2][i], j, 0});
        }
 
        while (pq.size() and dp[i].size() < k){
            auto [val, j, num] = pq.top(); pq.pop();
            dp[i].push_back(val);
            
            if (j < 0 or num + 1 >= dp[j].size())
                continue;
            
            if (j == i - 1)
                pq.push({dp[i - 1][num + 1], i - 1, num + 1});
            else 
                pq.push({dp[j][num + 1] + A[j + 2][i], j, num + 1});
        }
    }
    for (int i : dp[n])
        cout << i << " ";
    cout << "\n";

   


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
