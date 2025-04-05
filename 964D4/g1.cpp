#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

int q(int a, int b){
    cout << "? " << a << " " << b << " ";
    fflush(stdout);
    int v;
    cin >> v;
    return v;
}

void solve(){
    int l = 1, r = 999;
    while (r > l + 2) {
        int a = (2 * l + r) / 3;
        int b = (2 * r + l) / 3;
        cout << "? " << a << ' ' << b << endl;
        int resp; cin >> resp;
        if (resp == (a + 1) * (b + 1)) {
            r = a;
        }
        else if (resp == a * b) {
            l = b;
        }
        else {
            l = a; r = b;
        }
    }
    if (r - l == 2) {
        cout << "? 1 " << l + 1 << endl;
        int resp; cin >> resp;
        int ans = l;
        if (resp == l + 1)
            ans = r;
        else
            ans = l + 1;

        cout << "! " << ans << endl;
    }
    cout << "! " << r << endl;
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

//fflush(stdout);