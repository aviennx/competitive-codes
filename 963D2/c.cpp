#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

void solve(){
    int n, k;
        std::cin >> n >> k;
        
        std::vector<int> a(n, 0);
 
        for (int i = 0; i < n; i++) std::cin >> a[i];
 
        std::sort(a.begin(), a.end());
 
        int lo = a[n-1], hi = a[n-1]+k-1;
 
        for (int j = 0; j < n-1; j++) {
            int q = (a[n-1]-a[j])/k;
            int before = a[j]+q*k;
 
            int lo1 = before;
            int hi1 = before+k-1;
 
            if (q%2) {
                lo1 += k;
                hi1 += k;
            }
            
            lo = std::max(lo, lo1);
            hi = std::min(hi, hi1);
        }
 
        if (lo <= hi) std::cout << lo << std::endl;
        else std::cout << -1 << std::endl;

}


int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}

