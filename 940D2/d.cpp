#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define int long long

using namespace std;

const int max_N = 100005;
const int MOD = 1e9 + 7;

const int m = 32;
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    a.insert(a.begin(),0);
    
    for(int i = 1; i <= n; i++){
        a[i] ^= a[i-1];
    }
    
    vector<int> f(n+1);
    
    for(int i = 1; i <= n; i++){
        f[i] = a[i] ^ a[i-1];
    }
    
    vector<int> aage(m);
    vector<int> peeche(m);
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(1ll << j & a[i]){
                aage[j]++;
            }
        }
    }
    
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        
        for(int j = m-1; j >= 0; j--){
            if(1ll << j & f[i]){
                
                
                ans += aage[j] * peeche[j];
                ans += (n-i+1 - aage[j]) * (i - peeche[j]);
                
                break;
            }
        }
        
        
        for(int j = 0; j < m; j++){
            if(1ll << j & a[i]){
                aage[j]--;
                peeche[j]++;
            }
        }
    }
    
    
    
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
