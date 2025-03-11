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
    string s;
    cin >> s;
    int cnt[26] = {};
    for(char c :s)
        cnt[c - 'a']++;
    int need_rem = 0;
    for(int i : cnt)
        if(i % 2)
            need_rem++;
    if(k < need_rem - 1){
        yesno(0);
        return;
    }
    yesno(1);




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
