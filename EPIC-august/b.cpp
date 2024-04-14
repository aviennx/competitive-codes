#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

return;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int& i: a)
        cin >> i;
    for(int& i : b)
        cin >> i;
    bool flag = false;
    bool flag_base = false;
    bool flag_last = false;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i] && a[i] != b[n - 1])
            flag = 1;
        if(a[i] != b[i])
            flag_base = true;
        if(a[i] != b[n - 1 - i])    
            flag_last = true;
    }
    if(!flag_base || !flag_last)
        cout << "Bob\n";
    else
        cout << "Alice\n";
   


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
