#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    if(n == 1){
        cout << k << '\n';
        return;
    }
    int first = 0;
    int curr_sum = 0;
    for(int i = 0; i < 31; i++){
        if((1 << i) + curr_sum  <= k){
            first += (1 << i);
            curr_sum += (1 << i);
        }
    }
    int rem = k - curr_sum;
    int second = rem;
    cout << first << " " << second << " ";
    for(int i = 0 ; i < n - 2; i++)
        cout << 0 << " ";
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
