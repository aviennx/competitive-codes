#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;
const int MAX_V = 201;
bool achieve[MAX_V];
void solve(){
    int n, x;
    scanf("%d%d", &n, &x);
    for(int i = 1; i <= n + x; i++) {
        achieve[i] = false;
    }
    for(int i = 1; i <= n; i++) {
        int ranking;
        scanf("%d", &ranking);
        achieve[ranking] = true;
    }
    for(int k = n + x; k > 0; k--) {
        int v = 0;
        for(int i = 1; i <= k; i++) {
            if(!achieve[i]) v++;
        }
        if(v <= x) {
            printf("%d\n", k);
            return;
        }
    }

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
