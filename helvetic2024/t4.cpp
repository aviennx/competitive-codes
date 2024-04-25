#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
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

int n, m;
bool out(int x,int y){
    return x < 0 || y < 0 || x >= n || y >= m;
}
vector<pair<int,int>> dirs = {{1 , 0} , {-1 , 0} , {0 , 1} , {0, -1}};

void solve(){

vector<string> arr;
vector<vector<int>> visited, dist;


    cin >> n >> m;
    arr.resize(n);
    for(auto& i : arr)
        cin >> i;
    dist.resize(n, vector<int>(m, INT_MAX));
    visited.resize(n, vector<int>(m, 0));
    debug2D(dist);
    queue<pair<int,int>> q;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                if(arr[i][j] == '0'){
                    dist[i][j] = 0;
                    q.push({i, j});
                }else{
                    dist[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
    }
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(auto [nx, ny] : dirs){
            int X = x + nx;
            int Y = y + ny;
            if(out(X, Y))
                continue;
            int extra = arr[X][Y] - '0';
            if(dist[X][Y] <= dist[x][y] + extra)
                continue;
            q.push({X, Y});
            dist[X][Y] = dist[x][y] + extra;
        }
    }
    //debug2D(dist);
    int ans = 0;
    for(auto v : dist)
        for(auto i : v)
            if(i != INT_MAX)
                ans = max(ans, i);
    cout << (ans ==  INT_MAX ? -1 : ans )<< '\n';

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
