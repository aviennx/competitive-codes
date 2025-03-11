#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define ll long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
     int n;
    cin >> n;
    vector<ll> a(n);
    for(int& i : a)
        cin >> i;
    sort(a.begin(), a.end());
    ll ans = 0, sum = 0;
    for(int l = 0, r = n - 1; l <= r; ) {
        if(l == r) {
            if(sum >= a[l]) {
                ++ans;
                break;
            }
            if(a[l] == 0) break;
            else if(a[l] == 1) ++ans;
            else {
                ans += (a[l] - sum + 1) / 2 + 1;
            }
            break;
        }else if(sum + a[l] <= a[r]) {
            ans += a[l];
            sum += a[l];
            l++;
        }else {
            int val = a[r] - sum;
            a[l] -= val;
            sum = 0;
            ans += val;
            ans++;
            --r;
        }
    }
    cout << ans << "\n";

   


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

