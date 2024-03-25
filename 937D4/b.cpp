#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    bool flag = false;
    vector<vector<char>> b(2 * n, vector<char>(2 * n));
    for(int i = 0; i < 2 * n; i += 2){
        if(i / 2 % 2 == 0)
            flag = false;
        else
            flag = true; 

        for(int j = 0; j < 2 * n; j += 2){
            for(int r = i; r < i + 2; r++){
                for(int c = j; c < j + 2; c++)
                    if(!flag)
                    b[r][c] = '#';
                    else
                    b[r][c] = '.'; 
            }
            flag = !flag;
        }
    }
    for(auto v : b){
        for(auto c : v)
            cout << c;
        cout << '\n';
    }


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
