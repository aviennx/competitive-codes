#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>

const int N = 2e5 + 5;
int mat[1005][1005] = {};
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    vector<int> ans(n, (1 << 30) - 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)
                continue;
            
            ans[i] &= mat[i][j];
            ans[j] &= mat[i][j];

        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)
                continue;
            if((ans[i] | ans[j] )!= mat[i][j]){
                cout << "NO\n";
                return;
            }

        }
    }
    cout << "YES\n";
    for(int i : ans)
        cout << i << " ";
    cout << '\n';




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
