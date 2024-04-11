#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")
const int N = 2e5 + 5;
vector<int> tot;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int mb = 0;
    for(int& i : arr){
        cin >> i;
    }
    int ans = 0;
    int mxor = 0;
    for(int j = 1; j < n; j++){
        for(int i = 0; i < j; i++){
            int s = arr[i] ^ arr[j];
            mxor = max(mxor, s);
        }
    }
    for(int i = 0; i <= mxor;i++)
        tot[i] = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            tot[arr[i] ^ arr[j]]++;
    int sp = 0;
    for(int i = 0; i <= mxor; i++)
        ans += 4ll * tot[i] * (tot[i] - 1);
    cout << ans << '\n';
    cout << ans << '\n';

}
int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    tot.resize((1 << 21) - 1, 0);
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
