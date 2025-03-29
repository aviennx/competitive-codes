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
    string s;
    cin >> s;
    vector<int> arr(n);
    int index = 0;
    for(char c : s)
        arr[index++] = (c == 'U' ? 1 : 0);
    int ans = 0;
    for(int i : arr)
        ans += i;
    if (ans % 2) 
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
