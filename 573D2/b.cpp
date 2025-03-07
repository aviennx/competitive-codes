#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int idx[257] = {}, c[3][9] = {}, ans = 2;
    idx['m'] = 1;
    idx['p'] = 2;
    idx['s'] = 3;
    for(int i = 0; i < 3; ++i) {
        char buf[3];
        scanf("%s", buf);
        ++c[idx[buf[1]] - 1][buf[0] - '1'];
    }
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 9; ++j) {
            ans = min(ans, 3 - c[i][j]);
            if(j + 2 < 9)
                ans = min(ans, 3 - !!c[i][j] - !!c[i][j + 1] - !!c[i][j + 2]);
        }
    printf("%d\n", ans);
}


int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}

