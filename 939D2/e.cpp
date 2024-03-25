#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> lst(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> lst[i];
        }

        for (int it = 0; it < 1000; ++it) {
            for (int i = 0; i < n - 1; ++i) {
                lst[i + 1] = (lst[i] > lst[i + 1]) ? 0 : lst[i + 1] - lst[i];
            }
            lst[0] = (lst[0] < lst[n - 1]) ? 0 : lst[0] - lst[n - 1];
        }

        std::vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (lst[i] != 0 && lst[(i + n - 1) % n] == 0) {
                res.push_back(i + 1);
            }
        }

        std::cout << res.size() << '\n';
        for (int x : res) {
            std::cout << x << " ";
        }
        std::cout << '\n';
    }
    return 0;
}