 #include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n), pref(n, 0);
    unordered_map<int,set<int>> prev;
    int curr = 0;
    prev[0].insert(-1);
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
        curr ^= arr[i];
        pref[i] = curr;
        prev[curr].insert(i);
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        if((l && pref[r] == pref[l - 1] )|| (l == 0 && pref[r] == 0)){
            cout << "YES\n";
            continue;
        }
        int end_goal = pref[r];
        int start_goal = l ? pref[l - 1] : 0;
        auto it = prev[end_goal].lower_bound(l);
        int j = *it;
        it = prev[start_goal].upper_bound(r);
        it--;
        int i = *it;
        if(l <= j && j < i && j < r && i <= r)
            cout << "YES\n";
        else
            cout << "NO\n";
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
