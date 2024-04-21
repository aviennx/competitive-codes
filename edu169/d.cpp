#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

vector<char> characters = {'B', 'G', 'R', 'Y'};
void solve() {
    int n, q;
    cin >> n >> q;
    unordered_map<char,int> vx;
    for(int i = 0; i < 4; i++){
        vx[characters[i]] = i;
    }
    vector<int> msk(n + 2, 0);
    vector<vector<int>> pos(4);
    for (int i = 0; i < n; i++) {
        string s; 
        cin >> s;
        set<int> curr;
        for(auto c : s)
            curr.insert(vx[c]);
        int x = 0;
        for(int j : curr){
            x |= (1 << j);
            pos[j].push_back(i);
        }
        msk[i + 1] = x;
        //cout << x << " " ;
    }
    //cout << '\n';
    vector<vector<int>> last(n + 2, vector<int> ((1 << 4) - 1, 0)), next_(n + 2 , vector<int> ((1 << 4) - 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < ((1 << 4) - 1); j++){
            last[i][j] = last[i - 1][j];
            next_[n - i + 1][j] = next_[n - i + 2][j];
        }
        last[i][msk[i]] = i;
        next_[n - i + 1][msk[n - i + 1]] = (n - i + 1);
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < ((1 << 4) - 1); j++){
           cout << last[i][j] << " " << next_[i][j] << '\n';
        }
    }*/

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x >= y)
            swap(x, y);
        if (x == y || (msk[x] & msk[y]) != 0) {
            cout << abs(y - x) << '\n';
            continue;
        }
        int ans = INT_MAX;
        for (int i = 0; i < 4; i++){
            if((msk[x] >> i & 1) == 0)
                continue;
            for (int j = 0; j < 4; j++){
                if ((msk[y] >> j & 1 )== 0)
                    continue; 
                int m = (1 << i);
                m |= (1 << j);
                int l = INT_MAX, r = INT_MAX;
                if (last[x][m] != 0){
                    l = abs(x - last[x][m]) + abs(y - last[x][m]);
                }
                if (next_[x][m] != 0)
                    r = abs(next_[x][m] - x) + abs(next_[x][m] - y);
                ans = min(ans, l);
                ans = min(ans, r);
            }
        }
        if (ans == INT_MAX){
            cout << -1 << '\n';
        }else{
            cout << ans << '\n';
        }
    }
}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        //cout << t << '\n';
        solve();
    }
    return 0;
}
