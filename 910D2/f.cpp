#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

void solve(){
    int n, m; cin >> n >> m;
    
    vector <string> a(n);
    for (auto &x : a) cin >> x;
    
    pair <int, int> dp[n][m][2];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
        dp[i][j][0] = dp[i][j][1] = make_pair(INF, 0);
    }
    int cnt = 0;
    queue <array<int, 3>> q;
    
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
        if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && a[i][j] != '#'){
            dp[i][j][0] = make_pair(0, cnt++);
            q.push({i, j, 0});
        }
    }
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    while (!q.empty()){
        auto u = q.front(); q.pop();
        int x = u[0];
        int y = u[1];
        int z = u[2];
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#'){
                if (dp[nx][ny][0].first == INF){
                    dp[nx][ny][0] = dp[x][y][z];
                    dp[nx][ny][0].first++;
                    q.push({nx, ny, 0});
                } else if (dp[nx][ny][1].first == INF && dp[nx][ny][0].second != dp[x][y][z].second){
                    dp[nx][ny][1] = dp[x][y][z];
                    dp[nx][ny][1].first++;
                    q.push({nx, ny, 1});
                }
            }
        }
    }
    
    int px = -1, py = -1;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] == 'V'){
        px = i;
        py = j;
    }
    
    if (dp[px][py][0].first == INF){
        int ans = 0;
        for (auto x : a) for (auto y : x) ans += y == '.';
        cout << ans << "\n";
    } else if (dp[px][py][1].first == INF){
        int ans = 0;
        for (auto x : a) for (auto y : x) ans += y == '.';
        ans -= dp[px][py][0].first;
        cout << ans << "\n";
    } else {
        queue <pair<int, int>> q;
        vector<vector<int>> d(n, vector<int>(m, INF));
        d[px][py] = 0;
        q.push({px, py});
        
        while (!q.empty()){
            auto pi = q.front(); q.pop();
            
            for (int i = 0; i < 4; i++){
                int nx = pi.first + dx[i];
                int ny = pi.second + dy[i];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#' && d[nx][ny] == INF){
                    d[nx][ny] = d[pi.first][pi.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        int ans = INF;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
            ans = min(ans, d[i][j] + dp[i][j][0].first + dp[i][j][1].first);
        }
        
        ans = -ans;
        for (auto x : a) for (auto y : x) ans += y == '.';
        cout << ans << "\n";
    }

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