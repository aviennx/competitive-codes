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
    string s;
    cin >> s;
    int lc = 0, rc = 0, up = 0, dn = 0;
    int ind1 = -1, ind2 = -1, ind3 = -1, ind4 = -1;
    int index = -1;
    for(auto c : s){
        index++;
        if(c == 'N'){
            ind1 = index;
            up++;
        }
        else if(c == 'S'){
            ind2 = index;
            dn++;
        }
        else if(c == 'E'){
            ind3 =index;
            lc++;
        }
        else{
            ind4= index;
            rc++;
        }
    }
    if((rc + lc) % 2 || (up + dn) % 2){
        cout << "NO\n";
        return;
    }
    string ans(n, 'H');
    char currx = 'H', curry = 'H'; 
    for(int i = 0; i < n; i++){
        if(s[i] == 'S' || s[i] == 'N'){
            ans[i] = curry;
            if(curry == 'H')
                curry = 'R';
            else
                curry = 'H';
        }
        else{
            ans[i] = currx;
            if(currx == 'H')
                currx = 'R';
            else
                currx = 'H';
        }
    }
    if(lc % 2 ){
        ans[ind3] = currx;
        ans[ind4] = currx;
    }
    if(up % 2){
        ans[ind1] = curry;
        ans[ind2] = curry;
    }
    int all_same = true;
    char prev = 'H';
    for(auto c : ans){
        if(c != prev){
            all_same = false;
        }
        prev = c;
    }
    if(!all_same)
        cout << ans << '\n';
    else
        cout << "NO\n";


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
