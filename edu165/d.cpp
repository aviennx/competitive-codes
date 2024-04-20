#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int& i : a)
        cin >> i;
    for(int& i : b)
        cin >> i;
    vector<int> diff(n);
    for(int i = 0; i < n; i++){
        diff[i] = b[i] - a[i];
    }
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](auto i , auto j) {
        return b[i] < b[j];
    });

    vector<int> pref(n);
    for(int i = 0; i < n; i++){
        int index = ind[i];
        if(i)
            pref[i] = pref[i - 1];
        pref[i] += max(0ll, diff[index]);
    }
    int profit = 0;
    int loss = 0;
    int ans = 0;
    multiset<int> mt;

    for(int i = n - 1; i >= 0; i--){
        int index = ind[i];
        loss += a[index];
        mt.insert(a[index]);
        if(mt.size() > k){
            auto last = mt.rbegin();
            loss -= *last;
            mt.erase(mt.find(*last));
        }
        if(mt.size() == k && i > 0){
            profit = pref[i - 1];
            ans = max(ans, profit - loss);
        }
    }    
    if(k == 0)
        ans = pref[n - 1];
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
