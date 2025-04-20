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
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    int avoid = arr[0];
    if(arr.back() != avoid){
        //cout << "a\n";
        cout << 0 << '\n';
        return;
    }

    vector<int> cnt;
    bool done = false;
    for(int i = 1; i < n - 1; i++){
        if(arr[i] != avoid)
            cnt.push_back(i);
        if(arr[i] != avoid && arr[i - 1] != avoid)
            done = true;
    }
    if(done){
        //cout << "b\n";
        cout << 0 << '\n';
        return;
    }
    if(cnt.size() == 0){
        //cout << "c\n";
        cout << -1 << '\n';
        return;
    }
    int ans = min(cnt[0] - 0, n - cnt.back() - 1);
    for(int i = 1; i < cnt.size(); i++)
        ans = min(ans, cnt[i] - cnt[i - 1] - 1);
    //cout << "d\n";
    cout << ans << '\n';
    return;
   


}


int32_t main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
