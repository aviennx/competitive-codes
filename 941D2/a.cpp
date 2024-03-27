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
    unordered_map<int,int> freq;
    for(int& i : arr){
        cin >> i;
        freq[i]++;
    }
    vector<int> pq;
    for(auto [v, f] : freq)
        pq.push_back(f);
    sort(pq.begin(), pq.end());
    int ans = 0;
    while(!pq.empty() && pq.back() >= k){
        if(pq.size() == 1){
            pq.back() = min((int)pq.back(), k - 1);
            break;
        }
        int curr = pq.back();
        pq.pop_back();
        if(curr >= k)
            pq.back() += k - 1;

    }
    for(int i : pq)
        ans += i;
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
