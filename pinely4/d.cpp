#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

array<vector<int>, 2> manacher(const string& s)
{
    int n = s.size();
    array<vector<int>,2> p = {vector<int>(n+1), vector<int>(n)};
    for (int z = 0; z < 2; ++z) {
        for (int i = 0, l = 0, r = 0; i < n; ++i) {
            int t = r - i + !z;
            if (i < r) p[z][i] = min(t, p[z][l + t]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
                p[z][i]++, L--, R++;
            if (R > r) l = L, r = R;
        }
    }
    return p;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<array<int,2>> dp(n + 1, {0,0});
    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
        dp[i][1] += (n - i );
        dp[i][0] += 2 * (n - i);
        if(i < n - 1  && s[i] == s[i + 1]){
            dp[i][0] += dp[ i + 1][0];
            dp[i][1] += dp[i + 1][1];
        }else if(i < n - 1 && s[i] != s[i + 1]){
            dp[i][0] += dp[i + 1][1];
            dp[i][1] += dp[i + 1][0];
        }
        ans += dp[i][s[i] - '0'];

    }
    for(int i = 0; i < n; i++)
        cout << dp[i][0] << " " << dp[i][1] << "\n";
    cout << '\n';
    cout << ans << '\n';



}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    //primes = eratosthenesSieve(MAX_N);
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
