#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    string a, b;
    cin >> a >> b;
    string na, nb;
    na += a[0], nb += b[0];
    for(int i = 1 ; i < a.size(); i++){
        if(na > nb){
            na += min(a[i], b[i]);
            nb += max(a[i], b[i]);
        }else{
            nb += min(a[i], b[i]);
            na += max(a[i], b[i]);
        }
    }
    cout << na << endl;
    cout << nb << endl;
   


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
