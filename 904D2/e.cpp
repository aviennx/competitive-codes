#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n), freq(n + 1, 0);
    for(int& i : arr){
        cin >> i;
        freq[i]++;
    }
    vector<int> pair_count(n + 1, 0);
    vector<int> mult_count(n + 1, 0);
    vector<int> to_add(n  + 1, 1);
    for(int i = n; i >= 1; i--){
        for(int j = i; j <= n; j += i)
            mult_count[i] += freq[j];
        pair_count[i] = mult_count[i] * (mult_count[i] - 1) / 2;
        for(int j = 2 * i; j <= n; j += i)
            pair_count[i] -= pair_count[j];
    }
    for(int i = 1; i <= n; i++){
        if(!freq[i])
            continue;
        for(int j = i; j <= n; j += i)
            to_add[j] = 0;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(to_add[i])
            ans += pair_count[i];
    cout << ans << '\n';


}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
