#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long


void solve(){
    int n, L;
        std::cin >> n >> L;
        std::vector<std::pair<int, int>> v(n);
        for (int i = 0 ; i < n ; i++) {
            std::cin >> v[i].second >> v[i].first;
        }
        std::sort(v.begin(), v.end());

        int ans = 0;
        for (int l = 0 ; l < n ; l++) {
            std::multiset<int> s;
            int cur = 0;
            for (int r = l ; r < n ; r++) {
                s.insert(v[r].second);
                cur += v[r].second;
                while (!s.empty() && v[r].first - v[l].first + cur > L) {
                    int max_value = *s.rbegin();
                    cur -= max_value;
                    s.extract(max_value);
                }
                ans = std::max(ans, (int) s.size());
            }
        }
    cout << ans << '\n';
    return;
}


int32_t main(){
    fast;
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
