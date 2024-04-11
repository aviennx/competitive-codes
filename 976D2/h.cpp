#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")
typedef long long ll;

// Constants
int MOD = 1000000007;
int P;
// Function to compute (base^exp) % mod
ll pow_mod_func(ll base, ll exp, ll mod_val) {
    ll res = 1ll;
    base %= mod_val;
    while (exp > 0ll) {
        if (exp & 1LL)
            res = res * base % mod_val;
        base = base * base % mod_val;
        exp >>= 1LL;
    }
    return res;
}
bool valid(vector<int>& colors_prev, vector<int>& colors, vector<int>& colors_next){
    int N = colors_prev.size();
    bool found = false;
    for(int i=0; i<N; i++){
        if(colors_prev[i] == 0 && colors[i] == 1 && colors_next[i] == 2){
            found = true;
            break;
        }
        if(colors_prev[i] == 2 && colors[i] == 1 && colors_next[i] == 0){
            found = true;
            break;
        }
    }
    return !found;
}
int dp[51][85][85] = {};
void solve(){
    int N, M;
    cin >> N >> M >> P;
    MOD = P;
    vector<int> valid_columns;
    int total_assignments = pow(3, N);
    for(int num=0; num < pow(3, N); num++){
        vector<int> colors(N, 0);
        int tmp = num;
        for(int i=0; i<N; i++){
            colors[i] = tmp %3;
            tmp /=3;
        }
        bool invalid = false;
        if(N >=3){
            for(int i=0; i<=N-3; i++){
                if(colors[i]==0 && colors[i+1]==1 && colors[i+2]==2){
                    invalid = true;
                    break;
                }

            }
            for(int i=N - 1; i >= 2; i--){
                if(colors[i]==0 && colors[i-1]==1 && colors[i-2]==2){
                    invalid = true;
                    break;
                }
                
            }
        }
        if(!invalid){
            //cout << num << " ";
            valid_columns.push_back(num);
        }
    }
    //cout << '\n';
    int cc[3] = {};
    for(int i : valid_columns){
        cc[1]++;
        for(int j : valid_columns){
            dp[1][i][j] = 1;
        }
    }
    for(int i : valid_columns){
        for(int j : valid_columns){
            dp[2][i][j] += dp[1][j][0];
        }
    }
    if(M <= 2){
        ll total_grids = pow_mod_func(3, (ll)N * (ll)M, MOD);
        ll valid_grids = (total_grids - cc[M]) % MOD;
        cout << valid_grids << "\n";
        return;
    }
    for(int i = 2; i <= M - 1; i++){
        for(int& num : valid_columns){
            vector<int> colors(N, 0);
            int tmp = num;
            for(int i=0; i<N; i++){
                colors[i] = tmp %3;
                tmp /=3;
            }
            for(int& num_prev : valid_columns){
                vector<int> colors_prev(N, 0);
                int tmp1 = num_prev;
                for(int i=0; i<N; i++){
                    colors_prev[i] = tmp1 %3;
                    tmp1 /=3;
                }
                for(int& num_next : valid_columns){
                    vector<int> colors_next(N, 0);
                    int tmp2 = num_next;
                    for(int i=0; i<N; i++){
                        colors_next[i] = tmp2 %3;
                        tmp2 /=3;
                    }
                    if(valid(colors_prev, colors, colors_next)){
                        dp[i + 1][num_next][num] += dp[i][num][num_prev];
                        dp[i + 1][num_next][num] %= MOD;
                    }
                }

            }
        }
    }
    ll dp_sum =0LL;
    for(int i : valid_columns){
        for(int j : valid_columns){
            //cout << dp[M][i][j] << " ";
            dp_sum = (dp_sum + dp[M][i][j]) % MOD;
        }
        //cout << '\n';
    }
    cout << dp_sum << '\n';
    ll total_grids = pow_mod_func(3, (ll)N * (ll)M, MOD);
    ll valid_grids = (total_grids - dp_sum) % MOD;
    cout << valid_grids << "\n";
}
int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    //cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
