#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<int,int> m1, m2;
    vector<int> a(n), b(m);
    int match = 0;
    for(int& i : a)
        cin >> i;
    for(int& i : b){
        cin >> i;
        m2[i]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x = a[i];
        if(m2[x] > m1[x])
            match++;
        m1[x]++;
        if(i >= m - 1){
            if(i >= m){
                int y = a[i - m];
                if(m1[y] <= m2[y])
                    match--;
                m1[y]--;
            }
            if(match >= k)
                ans++;
        }
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
