#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool gen = false;
    int ans = 0;
    int cnt = 0;
    for(char c: s){
        if(c == '#')
            cnt = 0;
        else{
            ans++;
            cnt++;
        }
        if(cnt >= 3)
            gen = true;

    }
    if(gen){
        cout << "2\n";
        return;
    }else{
        cout << ans << '\n';
        return;
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
