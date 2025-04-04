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
    vector<int> arr(n);
    vector<int> nxt;
    string s;
    char prev = 'X';
    cin >> s;
    for(char c : s){
        if(c == '0' && prev == '0')
            continue;
        else
            nxt.push_back(c - '0');
        prev = c;
    }
    int cnt = 0;
    for(int i : nxt)
        cnt += i;
    if(cnt * 2 > nxt.size())
        cout << "YES\n";
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
