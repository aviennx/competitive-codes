#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
        int n, k;
        cin >> n >> k;
        k--;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int x = find_if(a.begin(), a.end(), [&](int v) { return v > a[k]; }) - a.begin();
        vector<int> b = a;
        int ans = 0;
        vector<int> indice = {0, x};
        for (int i : indice) {
            if (i == n || i > k) {
                continue;
            }
            swap(a[i], a[k]);
            int cnt = (i == 0 ? 0 : 1);
            for (int j = i + 1 ; j < n; j++) {
                if(a[j] > a[i])
                    break;
                cnt++;
            }
            ans = max(ans, cnt);
            a = b;
        }
        cout << ans << '\n';
    
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
