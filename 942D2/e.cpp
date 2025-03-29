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
    cin >> n ;
    vector<int> a(n);
    vector<int> pref1(n), pref2(n);
    for(int& i : a)
        cin >> i;
    for(int i = 0 ; i < n ; i++){
        pref1[i] = a[i] == 1;
        pref2[i] = a[i] == 2;
        if(i){
            pref1[i] += pref1[i - 1];
            pref2[i] += pref2[i - 1];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        int ones = pref1[r];
        int twos = pref2[r];
        if(l > 0){
            ones -= pref1[l - 1];
            twos -= pref2[l - 1];
        }   
        int rem = r - l + 1 - ones - twos;
        int a = min(ones,twos);
        int b = max(ones,twos);
        int gap = (b - a);
        int fillable = min(gap, rem);
        a += min(fillable , k);
        rem -= min(fillable, k);
        gap -= min(fillable, k);
        k -= min(fillable, k);
        if(gap !=0 ){
            int need = gap / 2;
            int ops = k;
            a += min(ops, need);
            b -= min(ops, need);
        }
        else{
                int plus = min(k, rem);
                a += plus / 2;
                b += (plus + 1)/ 2;
        }
        int ans = a * b;
        cout << ans << '\n';
    }    

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
