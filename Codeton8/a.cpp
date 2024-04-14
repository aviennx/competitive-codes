#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n , k;
    cin >> n >> k;
    if(n != k && k != 1){
        cout << -1 << '\n';
        return;
    }
    if(k == 1){
        cout << 1 << " ";
        for(int i = 2; i <= n; i++)
            cout << 2 << " ";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++)
        cout << 1 << " ";
    cout << '\n';



   


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
