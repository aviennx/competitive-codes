#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    int ans = 0;
    map<int, map<int, map<int, int>>> mp1, mp2, mp3;
    map<int,map<int,int>> tc1, tc2,tc3;
    for(int i = 0;i < n - 2; i++){
        int a = arr[i], b = arr[i + 1], c = arr[i + 2];
        if(tc1.count(a) && tc1[a].count(b))
            ans += tc1[a][b];
        if(tc2.count(b) && tc1[b].count(c))
            ans += tc1[b][c];
        if(tc3.count(a) && tc1[a].count(c))
            ans += tc1[a][c];
        if(mp1.count(a) && mp1[a].count(b) && mp1[a][b].count(c))
            ans -= mp1[a][b][c];
        if(mp2.count(a) && mp2[a].count(c) && mp2[a][c].count(b))
            ans -= mp2[a][c][b];
        if(mp3.count(b) && mp3[b].count(c) && mp3[b][c].count(a))
            ans -= mp3[b][c][a];
        tc1[a][b]++;
        tc2[a][c]++;
        tc3[b][c]++;
        mp1[a][b][c]++;
        mp2[a][c][b]++;
        mp3[b][c][a]++;
    }
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
