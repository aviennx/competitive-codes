#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, m ;
    cin >> n >> m;
    string arr[n];
    vector<vector<int>> check(2 , vector<int>(4, 0));
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        for(int j = 0; j < m; j++){
            char c = arr[i][j];
            int v = 0;
            if(c == 'W')
                v = 0;
            else
                v = 1;
            if(v == 0){
                if(i == 0)
                    check[0][0] = 1;
                if(i == n - 1)
                    check[0][1] = 1; 
                if(j == 0)
                    check[0][2] = 1;
                if(j == m - 1)
                    check[0][3] = 1;
            }else{
                 if(i == 0)
                    check[1][0] = 1;
                if(i == n - 1)
                    check[1][1] = 1; 
                if(j == 0)
                    check[1][2] = 1;
                if(j == m - 1)
                    check[1][3] = 1;
            }
        }
    }
    int a = 0, b = 0;
    for(int i = 0; i < 4; i++){
        a += check[0][i];
        b += check[1][i];
    }
    if(a == 4 || b == 4)
        yesno(1);
    else
        yesno(0);
   


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
