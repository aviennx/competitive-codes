#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
     int n;
        string s;
        cin >> n >> s;
        s = '$' + s;
        vector<int> subset;
        for (int i = 1; i <= n; ++i)
        {
            while (!subset.empty() && s[subset.back()] < s[i])
            {
                subset.pop_back();
            }
            subset.push_back(i);
        }
        int ans = 0;
        int m = (int)subset.size() - 1;
        while (ans <= m && s[subset[ans]] == s[subset[0]])
        {
            ans++;
        }
        ans = m - ans + 1;

        for (int i = 0; i <= m; ++i)
        {
            if (i < m - i)
            {
                swap(s[subset[i]], s[subset[m - i]]);
            }
        }
        for (int i = 2; i <= n; ++i)
        {
            if (s[i] < s[i - 1])
            {
                ans = -1;
                break;
            }
        }
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
