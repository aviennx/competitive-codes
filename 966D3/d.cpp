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
    vector<int> arr(n + 1, 0);
    string s;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    cin >> s;
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++){
        pref[i] = arr[i];
        pref[i] += pref[ i  - 1];
    }
    int tot = pref[n];
    int ans = 0;
    int last = n;
    for(int i = 1; i <= n; i++){
        int v = 0;
        if(s[i - 1] == 'R')
            continue;
        int curr = i;
        while(curr < last && last >= 1 && s[last - 1] == 'L' )
            last--;
        if(curr >= last)
            continue;
        if(curr >= 1 && last >= 0)
            v = pref[last--] - pref[curr - 1];
        ans += v;
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
    