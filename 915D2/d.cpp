#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        deque<pair<int, int>> dq;
        vector<int> f(n + 1);
        int mex = 0;
        int sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            f[a[i]]++;
            while (f[mex])
            {
                mex++;
            }
            dq.push_back({mex, 1});
            sum += mex;
        }
        int ans = sum;
        for (int i = 1; i < n; ++i)
        {
            pair<int, int> me = {a[i], 0};
            sum -= dq.front().first;
            dq.front().second--;
            if (dq.front().second == 0)
            {
                dq.pop_front();
            }
            while (!dq.empty() && dq.back().first >= a[i])
            {
                sum -= dq.back().first * dq.back().second;
                me.second += dq.back().second;
                dq.pop_back();
            }
            dq.push_back(me);
            sum = sum + me.first * me.second;
            dq.push_back({n, 1});
            sum += n;
            ans = max(ans, sum);
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
