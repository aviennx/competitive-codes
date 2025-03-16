#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n ,k ,d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for(int& i : a)
        cin >> i;
    vector<int> b(k);
    for(int& i : b)
        cin >> i;
    int ans = 0;

    for(int i = 0; i < d && i <= 2 * n ; i++){
        int cnt = 0;
        for(int i = 0; i < n; i++)
            cnt += (a[i] == i + 1);
        cnt += (d - 1 - i) / 2;
        ans = max(ans, cnt);
        for(int j = 0; j < b[i % k]; j++)
            a[j]++;
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
