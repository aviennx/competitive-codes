#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;

    ll best = 0;
    vector<pair<ll, int>> A(n);

    for (auto &[a, _] : A)
        cin >> a;
    for (auto &[_, b] : A)
        cin >> b;
    
    sort(A.begin(), A.end());
    
    for (int i = n - 1; i>= 0; i--){
        if (A[i].second == 1){
            int med = n / 2 - 1;

            if (med >= i)
                med++;

            best = A[med].first + A[i].first + k;
            break;
        }
    }

    // Remove the last element
    int lst = A.back().first;
    A.pop_back();

    auto chk = [&](int med){
        int less = 0;
        ll cst = 0;

        for (auto [a, b] : A)
            if (a < med)
                less++;
        
        for (int i = A.size() - 1; i >= 0 ; i--){
            if (A[i].first < med and A[i].second and less > n / 2 - 1){
                cst += med - A[i].first;
                less--;
            }
        }
        return less <= n / 2 - 1 and cst <= k;
    };

    int lo = 0, hi = 1e9;
    int ans = 0;
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if(chk(mid)){
            lo = mid + 1;
            ans = mid;
        }else
            hi = mid - 1;
    }
    cout << max(best, (ll)ans + lst) << "\n";

   


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
