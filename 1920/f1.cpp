#include<bits/stdc++.h>
using namespace std;
const int maxN = 3e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

vector<vector<int>> grid, dist;
vector<vector<int>> visited;

int n, m;

bool valid(int x,int y){
    return x >= 0 && y >= 0 && x < n && y < m ;
}

vector<pair<int,int>> dirs = {{1 , 0} , {-1 , 0} , {0 , 1} , {0, -1}};
vector<pair<int,int>> Alldirs = {{1 , 0} , {-1 , 0} , {1 , 1} , {-1, -1}, {0 , 1}, {0, -1} , {-1, 1}, {1 , -1}};

void debug1D(vector<pair<int,int>>& arr){
    int N = arr.size();
    cout << "------------------------" << endl;
    cout << "debugging array of size N = " << N << endl;

    for(auto j : arr)
            cout << j.first << ", " << j.second <<" :: " ;
    cout << endl;

    cout << "------------------------" << endl;
}


void debug2D(vector<vector<int>>& arr){
    int N = arr.size(), M = arr[0].size();
    cout << "------------------------" << endl;
    cout << "debugging array of size N = " << N << " and M = " << M << endl;

    for(int i = 0; i < N ;i++){
        for(int j : arr[i])
            cout << j << " ";
        cout << endl;
    } 

    cout << "------------------------" << endl;
}

void build_dist(vector<pair<int,int>>& q){

    vector<pair<int,int>> curr = q;
    vector<pair<int,int>> next;

    while((int)curr.size()){
        
        int sz = curr.size();

        //debug1D(curr);

        for(int i = 0; i < sz; i++){
            auto [x, y]  = curr[i];
            //cout << "F ";
            for( auto [nx, ny] : dirs){
                int X = x + nx;
                int Y = y + ny;
                if(!valid( X, Y))
                    continue;
                if(dist[X][Y] > dist[x][y] + 1){
                    next.push_back({X , Y});
                    dist[X][Y] = dist[x][y] + 1;
                }
            }

        }
        //debug1D(next);
        swap(curr , next);
        next.clear();
    }
    //cout << "Error";
}

bool valid_grid(int x, int y, int minAllowed, pair<int,int> island_start){

    if(dist[x][y] < minAllowed)
        return false;

    for(int i = 0; i < n; i++)
        std::fill(visited[i].begin(), visited[i].end(), 0);


    vector<pair<int,int>> curr = {{x , y}};

    //cout << minAllowed << " is min Allowed" << endl;
    while(!curr.empty()){
        vector<pair<int,int>> next;
        int sz = curr.size();

        for(int i = 0; i < sz; i++){
            auto [x, y] = curr[i];
            for( auto [nx, ny] : dirs){
                int X = x + nx;
                int Y = y + ny;
                if(valid( X, Y) && grid[X][Y] != 1 && dist[X][Y] >= minAllowed && !visited[X][Y] ){
                    next.push_back({X , Y});
                    visited[X][Y] = 1;
                }
            }
        }
        swap(curr , next);

    }

    //debug2D(visited);

    curr.push_back({island_start});

    while(!curr.empty()){
        vector<pair<int,int>> next;
        int sz = curr.size();

        for(int i = 0; i < sz; i++){
            auto [x, y] = curr[i];
            for( auto [nx, ny] : Alldirs){
                int X = x + nx;
                int Y = y + ny;
                if(valid( X, Y) && !visited[X][Y] ){
                    if( X == 0 || X == n-1 || Y == 0 || Y == m - 1)
                        return false;
                    next.push_back({X , Y});
                    visited[X][Y] = 1;
                }
            }
        }
        swap(curr , next);
    }
    return true;
}


void solve(){
    int q;
    cin >> n >> m >> q;

    grid.resize(n);
    visited.resize(n);
    dist.resize(n);

    for(int i = 0; i < n; i++){
        grid[i].resize(m,0);
        visited[i].resize(m,0);
        dist[i].resize(m,maxN);
    }

    vector<pair<int,int>> bfs_queue;
    pair<int,int> island_start;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == '#'){
                grid[i][j] = 1;
                island_start = {i , j };
            }
            else if(s[j] == 'v'){
                bfs_queue.push_back({i,j});
                dist[i][j] = 0 ;
            }
        }
    }

    build_dist(bfs_queue);

    /*debug2D(grid);
    debug2D(dist);*/


    for(int i = 0; i < q; i++){
        //cout << "QUERY NUMBER " << i <<"START" << endl ;
        //cout << " __________________  " <<endl;
        int x, y;
        cin >> x >> y;
        x-- , y--;
        int low = 0, high = m + n;
        int ans = 0;
        //cout << "START "<< x << " " << y <<endl;
        //cout << " ---> "<<endl; 
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(valid_grid(x, y, mid, island_start)){
                ans = max(ans,mid);
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        //cout << "QUERY NUMBER " << i << " : ANS :: " << ans << endl;
        cout << ans << endl;
    }
    
    return ;

}


int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
//    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
