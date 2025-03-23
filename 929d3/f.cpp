#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define int long long 

int board[1005][1005], len[1005][1005];

void solve(){
    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> board[i][j];
            len[i][j] = 1e18;
        }
    }
 
    queue<pair<int,int>> q;
    q.push({0,0});
    len[0][0] = 0;
    while(q.size())
    {
        auto [x,y] = q.front();
        q.pop();
        int t = len[x][y];

        if(len[(x+1)%n][y]==1e18)
        {
            if(!board[(x+1+t)%n][y]&&!board[(x+2+t)%n][y])
            { 
                len[(x+1)%n][y] = t + 1;
                q.push({(x+1)%n,y});
            }
        }
        if(y+1<m&&len[x][y+1]==1e18)
        {
            if(!board[(x+1+t)%n][y+1])
            {
                len[x][y+1] = t + 1;
                q.push({x,y+1});
            }
        }
    }

    int ans = 1e18;

    for(int i=0;i<n;i++)
        if(len[i][m-1]!=1e18)
            ans = min(ans,min(i+1,n-1-i)+len[i][m-1]);

    cout << ( ans == 1e18 ? -1 : ans ) << '\n';

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



