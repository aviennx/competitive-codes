class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        long long ans = 0;
        int n = damage.size();
        int ft = 0;
        long long curr = 0;
        long long ans = 0;
        vector<int> times(n);
        for(int i = 0; i < n; i++){
            times[i] = ceil(health[i] / power);
            ft += times[i];
        }
        vector<array<long long,4>> v;
        pri
        for(int i = 0; i < n; i++){
            curr += (damage[i]);
            v.push_back({damage[i], health[i], times[i], health[i] / times[i]});
        }
        sort(v.begin(), v.end(), [&](const auto& a, const auto& b) {
            return (b[0] * ((a[1] + power - 1) / power)) < (a[0] * ((b[1]+ power - 1) / power));
        });
        for (const auto& x : v) {
            ans = ans + 1ll * curr * (x[1] + power - 1)/power;
            curr -= x[0];
        }
        return ans;
        
    }
};
