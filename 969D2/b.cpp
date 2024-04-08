#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());
    int curr_max = arr.back();
    vector<int> fin;
    for(int i = 0; i < q; i++){
        char c;
        int l, r;
        cin >> c >> l >> r;
        int val = (c == '-') ? -1 : 1;
        if(l <= curr_max && curr_max <= r)
            curr_max += val;
        fin.push_back(curr_max);
    }
    for(int i : fin)
        cout << i << " ";
    cout << '\n';
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
