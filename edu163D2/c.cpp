#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;


bool valid(int x, int y , int n ){
    return x >= 0 && x < 2 && y >= 0 && y < n;
}
vector<pair<int,int>> dirs = {{1 , 0} , {-1 , 0} , {0 , 1} , {0, -1}};
void solve(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(2, vector<int> (n,0));
    queue<pair<int,int>> q;
    q.push({0,0});
    dp[0][0] = 1;

    while(!q.empty() && !dp[1][n - 1]){
        auto [x, y] = q.front();
        q.pop();
        for(auto [x1, y1] : dirs){
            int nx = x + x1, ny = y + y1;
            if(!valid(nx, ny, n))
                continue;
            char c;
            if(nx == 1){
                c = s2[ny];
            }else
                c = s1[ny];

            if(c == '<')
                ny--;
            else
                ny++;
            if(!valid(nx, ny, n))
                continue;
            if(dp[nx][ny])
                continue;
            dp[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    if(dp[1][n - 1])
        cout << "YES\n";
    else
        cout << "NO\n";

   


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
