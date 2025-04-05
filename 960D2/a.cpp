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
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());
    int mx = *max_element(arr.begin(), arr.end());
    vector<int> freq(100, 0);
    int cnt = 0;
    for(int i : arr)
        if(i == mx)
            cnt++;
    if(cnt % 2){
        cout << "YES\n";
        return;
    }
    int prev = arr.back();
    for(int i : arr)
        freq[i]++;
    for(int i = 50 ; i >= 1 ; i--){
        freq[i] += freq[i + 1];
        if(freq[i] % 2){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
   


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
