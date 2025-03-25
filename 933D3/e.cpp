#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n, m , k ,d;
    cin >> n >> m >> k >> d;

    vector<vector<int>> mat(n, vector<int>(m));
    vector<int> pref(n);


    for(auto& arr : mat)
        for(int& i : arr)
            cin >> i;

    for(int i = 0; i < n; i++){
        vector<int> tot(m);
        multiset<int> curr_set ;
        for(int j = 0; j < m; j++){
            if((int)curr_set.size() > d + 1){
                int to_remove = tot[j - d - 2];
                auto it = curr_set.find(to_remove);
                curr_set.erase(it);
            }
            tot[j] = mat[i][j] + 1;
            if(!curr_set.empty())
                tot[j] += *curr_set.begin();
            curr_set.insert(tot[j]);
        }
        pref[i] = tot[m - 1] + (i ? pref[i - 1] : 0);

    }

    int ans = LLONG_MAX;
    for(int i = k - 1; i < n; i++)
        ans = min(ans, pref[i] - (i - k >= 0 ? pref[i - k] : 0));
    cout << ans << '\n';
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
