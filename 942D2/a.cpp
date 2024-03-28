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
    vector<int> a(n), b(n);
    for(int& i : a)
        cin >> i;
    for(int& i : b)
        cin >> i;
    int ans = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while(true){
        sort(a.begin(), a.end());
        bool flag = true;
        for(int i = 0 ; i < n ; i++){
            if(a[i] > b[i]){
                    flag = false;
                    break;
            }
        }
        if(flag == true)
            break;
        a[n - 1] = 0;
        ans++;
    }


    cout << ans << '\n';


   


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
