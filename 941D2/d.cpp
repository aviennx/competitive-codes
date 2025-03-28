#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;
using namespace std;


void solve(){
    int n, k; cin >> n >> k;
    int st = 1;
    vector<int> nums;
    while (2*st-1 < k) {
        nums.push_back(st);
        st = st*2;
    }
    int not_ok = st;
    st = st*2;
    while (nums.size() <= 19) {
        nums.push_back(st);
        st = st*2;
    }
    int add = k - not_ok;
    nums.push_back(k + 1 + not_ok);
    nums.push_back(add);
    nums.push_back(k+1);
    cout << nums.size() << "\n";
    for (auto &x: nums)
        cout << x << " ";
    cout << "\n";
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
