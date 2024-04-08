#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

class Solution {
public:
    
class Solution {
public:
    int search(int i, set<int>& st, int curr, vector<vector<pair<int, int>>>& grid2) {
        if (i == grid2.size()) {
            return curr;
        }
        int ans = curr;
        for (auto& [value, j] : grid2[i]) {
            if (st.find(value) == st.end()) {
                st.insert(value);
                ans = max(ans, search(i + 1, st, curr + value, grid2));
                st.erase(value);
            }
        }
        
        return ans;
    }
    int maxScore(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        map<int, int> dp, next;
        vector<vector<int>> copy(n, vector<int>(m , 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                copy[i][j] = grid[i][j];
        for(auto& v : copy)
            sort(v.begin(), v.end());
        vector<vector<pair<int, int>>> grid2(n);
        set<int> st;
        int cnt = 0;
        for (auto& i : grid) {
            vector<pair<int, int>> bestr;
            for (int j = 0; j < i.size(); ++j) {
                bestr.push_back({i[j], j});
            }
            sort(bestr.rbegin(), bestr.rend());
            for(auto g : bestr)
                grid2[cnt].push_back(g);
            cnt++;
        }
        int ans = search(0, st, 0, grid2);
        return ans;
    }
};
};

int32_t main(){
    vector<vector<int>> grid = {
        {3},
        {1},
        {4}
    };
    
    Solution solution;
    int result = solution.maxSumSelection(grid);
    cout << "Maximum sum: " << result << endl;
    return 0;
}
