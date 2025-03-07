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
    if(n % 4 == 1){
        cout << 0 << " " << 'A' << '\n'; 
    }else if(n % 4 == 2){
        cout << 1 << " " << 'B' << '\n';
    }else if(n % 4 == 3){
        cout << 2 << " " << 'A' << '\n';
    }else{
        cout << 1 << " " << 'A' << '\n';
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
