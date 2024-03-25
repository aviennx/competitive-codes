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
    string s;
    cin >> s;
    int ans = n;
    for(int k = 1; k <= sqrt(n); k++){
        if(n % k)
            continue;
        int k1 = k, k2 = n / k;
        string a = s.substr(0, k1), b = s.substr(0, k2);
        string c = s.substr(n - k1, k1), d = s.substr(n - k2, k2);
        int c1 = 0, c2 = 0 , c3 = 0, c4 = 0;
        for(int j = 0; j < n ; j++){
            if(a[j % k1] != s[j]){
                c1++;
            }
        }
        for(int j = 0; j < n; j++){
            if(b[j % k2] != s[j]){
                c2++;
            }
        }
        for(int j = 0; j < n ; j++){
            if(c[j % k1] != s[j]){
                c3++;
            }
        }
        for(int j = 0; j < n; j++){
            if(d[j % k2] != s[j]){
                c4++;
            }
        }
        int cx = min(c1, c3);
        int cx2 = min(c2, c4);
        if(cx <= 1)
            ans = min(ans, k1);
        if(cx2 <= 1)
            ans = min(ans , k2);

        

        /*
        cout << k1 << " " << a << endl;
        cout << k2 << " " << b << endl;
        cout << c1 << " " << c2 << endl;
        */
    }
    cout << ans << '\n';

   


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
