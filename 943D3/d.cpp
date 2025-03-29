#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    vector<int> perm(n + 1), arr(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> perm[i];
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    int suma = 0, sumb = 0;
    int ansa = 0, ansb = 0;
    for(int i = 1; i <= min(k , n); i++){
        ansa = max(ansa, suma + (k - i + 1) * arr[pb]);
        ansb = max(ansb, sumb + (k - i + 1) * arr[ps]);
        suma += arr[pb];
        sumb += arr[ps];
        pb = perm[pb];
        ps = perm[ps];
    }
    if(ansa > ansb)
        cout << "Bodya\n";
    else if(ansa < ansb)
        cout << "Sasha\n";
    else
        cout << "Draw\n";

   


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
