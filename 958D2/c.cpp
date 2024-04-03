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
    cin >> n;
    vector<int> ans;
    vector<int> cnt(64, 0);
    for(int i = 0; i < 64; i++)
        if((1ll << i) & n)
            cnt[i]++;
    int l = 0, r = 0;
    ans.push_back(n);
    vector<int> arr;
    for(int i = 0; i < 64; i++)
        if(cnt[i])
            arr.push_back(i);
    l = -1;
    r = 0;
    while(r < arr.size()){
        int curr = ans.back();
        curr -= (1ll << arr[r]);
        if(l != -1)
            curr |= (1ll << arr[l]);
        r++;
        l++;
        if(curr != 0)
            ans.push_back(curr);
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i : ans)
        cout << i << " ";
    cout << '\n';

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
