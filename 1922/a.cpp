#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 
using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second

void solve(){
    int n;
    cin >> n;
    string a,b,c;
    cin >> a >> b >> c;

    int low = 0 , high = 0;
    for(int i=0;i<n;i++){
        low += a[i] == b[i] && a[i] != c[i];
        high += a[i] != c[i] && b[i] != c[i]; 
    }
    if( low || high )
        cout << "YES" << endl;
    else
        cout << "NO" <<endl;
 
}


int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
