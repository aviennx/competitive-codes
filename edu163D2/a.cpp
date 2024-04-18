#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    if(n % 2){
        cout << "NO\n";
        return;
    }
    string ans = "";
    char curr = 'A';
    while(n != 0){
        ans += curr;
        ans += curr;
        curr ++;
        if(curr > 'Z')
            curr = 'A';
        n -= 2;
    }
    cout << "YES\n";
    cout << ans << endl;
   


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
