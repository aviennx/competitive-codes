#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    set<int> avoid = {x};
    int ans = 0;
    for(int i : arr){
        for(int d : avoid){
            if(d % i)
                continue;
            else if(d == i){
                avoid = {x , x / i};
                ans++;
                break;
            }else
                avoid.insert(d / i);
        }
    }
    cout << ans + 1 << '\n';
    


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
