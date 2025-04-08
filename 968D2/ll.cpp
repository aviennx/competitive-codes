#include <iostream>
#include <vector>
#include <algorithm>

const int N = 4e5 + 5;
std::vector<int> edges[N];
int cnt[N], dp[N];

// Function to compute the two smallest MEX values
std::pair<int, int> computeMEX(const std::vector<int>& sorted_set) {
    int mex1 = 0, mex2 = 1;
    for (int x : sorted_set) {
        if (x == mex1) mex1++;
        else if (x == mex2) mex2++;
        else if (x > mex1 && mex1 + 1 < mex2) mex1++;
        else if (x > mex2) break;
    }
    return {mex1, mex2};
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    int V = 0;

    // Process input sets and build graph
    for (int i = 1; i <= n; i++) {
        int l;
        std::cin >> l;
        std::vector<int> cur(l);
        for (auto &x : cur) std::cin >> x;
        std::sort(cur.begin(), cur.end());

        auto [x, y] = computeMEX(cur);
        edges[x].push_back(y);
        cnt[x]++;
        V = std::max(V, y);
    }

    // Dynamic programming to find maximum values
    long long ans = 0;
    int tmp = 0;
    for (int i = 0; i <= V; i++) dp[i] = i;
    for (int i = V; i >= 0; i--) {
        for (int p : edges[i]) dp[i] = std::max(dp[i], dp[p]);
        if (cnt[i] > 1) tmp = std::max(tmp, dp[i]);
        if (cnt[i] > 0) tmp = std::max(tmp, i);
    }

    // Calculate the sum of maximum values
    for (int i = 0; i <= std::min(V, m); i++) {
        ans += std::max(dp[i], tmp);
    }

    // Add the sum of remaining values if m > V
    long long l = V + 1;
    long long r = m;
    if (l <= r) {
        ans += (r - l + 1) * (r + l) / 2;
    }

    // Clean up and output result
    for (int i = 0; i <= V; i++) {
        cnt[i] = dp[i] = 0;
        edges[i].clear();
    }
    std::cout << ans << '\n';
}

int main() {
    solve();
    return 0;
}