#include <algorithm>
#include <vector>

class Solution {
public:
    long long minDamage(int power, std::vector<int>& damage, std::vector<int>& health) {
        int n = damage.size();
        std::vector<std::pair<int, int>> enemies;
        for (int i = 0; i < n; ++i) {
            enemies.push_back({damage[i], health[i]});
        }

        // Sort enemies based on the custom comparator
        std::sort(enemies.begin(), enemies.end(), [&](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            long long valueA = static_cast<long long>(a.first) * ((b.second + power - 1) / power);
            long long valueB = static_cast<long long>(b.first) * ((a.second + power - 1) / power);
            return valueB < valueA;
        });

        long long totalDamage = 0;
        long long currentDamage = 0;

        // Calculate the total damage dealt to Bob
        for (const auto& enemy : enemies) {
            currentDamage += enemy.first;
        }

        for (const auto& enemy : enemies) {
            int hits = (enemy.second + power - 1) / power;
            totalDamage += hits * currentDamage;
            currentDamage -= enemy.first;
        }

        return totalDamage;
    }
};
