#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int MAX_N = 1005;
const int MAX_K = 105;
const int INF = 1e9;

int n, k;
std::vector<std::pair<int, int>> items;
std::vector<std::vector<int>> cost;
std::vector<std::vector<int>> memo;

int calculate_cost(int idx, int p) {
    if (p == 0) return 0;
    if (idx == 0 || p < 0) return INF;

    if (cost[idx][p] != -1) return cost[idx][p];

    int a = items[idx-1].first, b = items[idx-1].second;
    int min_cost = INF;

    for (int r = 0; r <= p; r++) {
        int c = p - r;
        if (r > a || c > b) continue;
        min_cost = std::min(min_cost, r * b + c * a - r * c);
    }

    return cost[idx][p] = min_cost;
}

int solve(int idx, int remaining) {
    if (idx == n && remaining == 0) return 0;
    if (idx == n || remaining < 0) return INF;

    if (memo[idx][remaining] != -1) return memo[idx][remaining];

    int result = INF;
    for (int t = 0; t <= remaining; t++) {
        result = std::min(result, solve(idx + 1, remaining - t) + calculate_cost(idx + 1, t));
    }

    return memo[idx][remaining] = result;
}

int main() {
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t;
    std::cin >> t;
    while(t--){
    std::cin >> n >> k;

    items.resize(n);
    cost.assign(n + 1, std::vector<int>(k + 1, -1));
    memo.assign(n + 1, std::vector<int>(k + 1, -1));

    for (int i = 0; i < n; i++) {
        std::cin >> items[i].first >> items[i].second;
    }

    int result = solve(0, k);
    if (result == INF) result = -1;
    std::cout << result << '\n';
}

    return 0;
}