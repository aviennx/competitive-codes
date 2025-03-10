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
        vector <int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> res;
        for(int i = 0; i < n; i++){
            int l = 1, r = i + 1;
            while(l <= r){
                int m = (l + r) / 2;
                if(a[i - m + 1] >= m){
                    l = m + 1;
                }else{
                    r = m - 1;
                }
            }
            res.push_back(r);
        }
        for(auto i : res){
            cout << i << " ";
        }
        cout<<"\n";
   


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
