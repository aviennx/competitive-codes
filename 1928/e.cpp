#include <cassert>
#include <initializer_list>
#include <numeric>
#include <vector>
#include <iostream>
#include <utility>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb emplace_back

const int INF = 1e9 + 10;
const ll INFLL = 1e18;

void solve() {
    int n, x, y, S;
    cin >> n >> x >> y >> S;
    vector<int> dp(S + 1, INF);
    dp[0] = 0;
    for (int k = 1; k <= S; k++) {
        for (int l = 2; (l * (l - 1)) / 2 <= k; l++) {  // just 0 is never optimal
            dp[k] = min(dp[k], dp[k - (l * (l - 1)) / 2] + l);
        }
        assert(dp[k] <= 2 * k);
    }
    for (ll k = 0; k < n; k++) {
        ll prevSum = (k + 1) * x + (k * (k + 1)) / 2 * y;
        if (prevSum > S) {
            continue;
        }
        ll needSum = S - prevSum;
        needSum -= (n - k - 1) * (x % y);
        if (needSum < 0) {
            continue;
        }
        if (needSum % y != 0) {
            continue;
        }
        needSum /= y;
        assert(needSum <= S);
        if (dp[needSum] <= n - k - 1) {  // we found the answer
            vector<int> a(n);
            a[0] = x;
            for (int i = 1; i <= k; i++) {  // construct prefix
                a[i] = a[i - 1] + y;
            }
            for (int i = k + 1; i <= k + (n - k - 1) - dp[needSum];
                 i++) {  // fill the rest like 0 0 0 ...
                a[i] = x % y;
            }
            int i = k + (n - k - 1) - dp[needSum] + 1;  // first free index
            vector<int> lens;                           // recover lengths of the segments
            while (needSum != 0) {
                for (int l = 2; (l * (l - 1)) / 2 <= needSum; l++) {
                    if (dp[needSum] == dp[needSum - (l * (l - 1)) / 2] + l) {
                        lens.pb(l);
                        needSum -= (l * (l - 1)) / 2;
                        break;
                    }
                }
            }
            for (auto &len : lens) {
                for (int j = 0; j < len; j++) {
                    a[i] = (x % y) + y * j;
                    i++;
                }
            }
            cout << "YES\n";
            for (auto &c : a) {
                cout << c << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}