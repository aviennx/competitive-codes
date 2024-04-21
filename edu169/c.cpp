#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    sort(arr.begin() ,arr.end());
    int mid = n / 2;
    int v = arr[mid];
    int s1 = 0;
    int s2 = 0;
    int curr = 0;
    for(int i = n - 1; i >= 0; i--){
        if(curr){
            s1 += arr[i];
            if(arr[i] < arr[i + 1] && k){
                int d = arr[i + 1] - arr[i];
                int x = min(k , d);
                k -= x;
                s1 += x;
            }
        }
        else
            s2 += arr[i];
        curr ^= 1;
    }
    cout << s2 - s1 << '\n';

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
