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
    vector<int> s(n);
    for(int& i : s)
        cin >> i;
    int a = 0, b = 0;
    for(auto c : s){
        if(c == 0)
            a++;
        else
            b++;
    }
    if(b <= n / 2){
        cout << a << '\n';
        for(int i = 0; i < a; i++)
            cout << 0 << " ";
    }
    else{
        if(b % 2)
            b--;
        cout << b << '\n';
        for(int i = 0; i < b; i++)
            cout << 1 << " ";
    }
    cout << '\n';
   


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
