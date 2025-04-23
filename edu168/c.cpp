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
    multiset<int> st;
    string temp = s;
    int curr = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i % 2 == 1){
            if(s[i] == '(')
                curr--;
            else
                curr++;
            if(curr != -1)
                continue;
        }
        if (curr == -1) {
            int index = *st.begin();
            s[index] = ')';
            temp[index] = ')';
            st.erase(st.begin());
            curr += 2;
            if(i % 2)
                continue;
        }
        curr--;
        s[i] = '(';
        temp[i] = '(';
        st.insert(i);
    }
    curr = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(temp[i] == '(')
                curr++;
            else
                curr--;
        ans += curr;
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
