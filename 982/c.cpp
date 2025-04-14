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
    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        arr[i] = {val + i - n, i + 1};
    }
    sort(arr.begin(), arr.end(), [&](const pair<int,int> &a, const pair<int,int> &b) -> bool{
        if(a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    });
    map<int, int> mx;
    mx[0] = n;
    int ans = n;
    for(auto &x : arr){
        int y = x.first;
        int j = x.second;
        auto it = mx.find(y);
        if(it == mx.end())
            continue;
        int next = it->second + j - 1;
        ans = max(ans, next);
        int curr = y + j - 1;
        if(mx.find(curr) == mx.end() || 
           mx[curr] < next){
            mx[curr] = next;
        }
    }
    
    cout << ans << "\n";


}
int32_t main(){
freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
     for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
