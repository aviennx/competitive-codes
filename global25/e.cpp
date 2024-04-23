#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

bool pal(string& S)
{

    string P = S;
 
    reverse(P.begin(), P.end());

    if (S == P) {
        // Return "Yes"
        return 1;
    }
    // Otherwise
    else {
        // return "No"
        return 0;
    }
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    if(!pal(s)){
        yesno(1);
        cout << 1 << '\n';
        cout << s << '\n';
        return;
    }
    int cnt[26] = {};
    for(auto c : s)
        cnt[c- 'a']++;
    int v = 0;
    for(int i = 0; i < 26; i++){
        if(cnt[i])
            v++;
    }
    if(v == 1){
        yesno(0);
        return;
    }
    int r = 1;
    while(s[r] == s[0])
        r++;
    string start = s.substr(0, r + 1), end = s.substr(r + 1, n - r - 1);
    if(!pal(end)){
        yesno(1);
        cout << 2 << '\n';
        cout << start << " " << end << '\n';
        return;
    }
    if(r == 1 || (n % 2 && r == n / 2)){
        yesno(0);
        return;
    }
    start = s.substr(0, r + 2), end= s.substr(r + 2, n - r - 2);
     yesno(1);
        cout << 2 << '\n';
        cout << start << " " << end << '\n';



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
