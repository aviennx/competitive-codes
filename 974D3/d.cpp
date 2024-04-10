#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, d, k;
    cin >> n >> d >> k;
    int bestm = -1, bestf = -1;
    int sm = INT_MAX, sf = -1;
    vector<int> arr(n + 2, 0), arr1(n + 2, 0);
    while(k--){
        int l, r;
        cin >> l >> r;
        arr[l]++;
        arr1[r]++;
    }
    for (int i=0;i<n;i++)
        arr[i+1] += arr[i];
    for (int i=0;i<n;i++)
        arr1[i+1] += arr1[i];
    int cnt = 0;
    for(int i = d; i <= n; i++){
        cnt = arr[i];
        cnt -= arr1[i - d];
        if(cnt > sf){
            sf = cnt;
            bestf = i - d + 1;
        }
        if(cnt < sm){
            sm = cnt;
            bestm = i - d + 1;
        }
    }
    cout << bestf << " " << bestm << '\n';



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
