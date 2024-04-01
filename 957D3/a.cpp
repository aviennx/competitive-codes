#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    multiset<int> st;
    st.insert(a);
    st.insert(b);
    st.insert(c);
    for(int i =0 ; i < 5; i++){
        int curr = *st.begin();
        st.erase(st.begin());
        curr++;
        st.insert(curr);
    }
    int ans = 1;
    for(int i : st)
        ans *= i;
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
