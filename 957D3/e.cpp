#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;
int modPow(long long x, int y)
{
    long long ans=1;
    if (y == 0)
        return 1;
    while(y>0){
        if(y % 2 == 1)
            ans = ans * x;
        y >>= 1;
        x = x * x;
    }
    return ans;
}
void solve(){
    int n;
    cin >> n;
    int def_val = n;
    string s = to_string(n);
    int len = s.size();
    for(int i = 0; i < 4; i++)
        s = s + s;
    vector<pair<int,int>> ans;
    int cnt = 0;
    for(int a = 1; a <= 10000; a++){
        int remainder = 0;
        for(int j = 1; j <= min(11ll, len * a); j++){
            remainder = remainder * 10 + s[j - 1] - '0';
            int b = len * a - j;
            if(b >= 1 && b <= 10000 && remainder == n * a - b)
                ans.push_back({a, b});
        }
    }
    cnt = ans.size();
    cout << cnt << "\n";
    for(auto [x, y] : ans)
        cout << x << " " << y << '\n';
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
