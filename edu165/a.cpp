#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr){
        cin >> i;
        i--;
    }
    bool duo = false;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            if(i == j)
                continue;
            if(arr[i] == j && arr[j] == i)
                duo  = true;
        }
    }
    if(duo)
        cout << 2 << '\n';
    else
        cout << min(n, 3ll) << '\n';


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
