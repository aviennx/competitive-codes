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
    vector<pair<int,int>> vals(2*n);
    vector<int> c(n);
    for(int i = 0; i < 2 * n; i++){
        cin >> vals[i].first;
        if(i < n){
            vals[i].second = 1;
        }else
            vals[i].second = 0;
    }
    for(int& i : c)
        cin >> i;

    sort(c.rbegin(), c.rend());
    sort(vals.begin() , vals.end());
    int ans = 0;
    vector<pii> st;
    vector<int> len;
    int index = 0;
    for(auto [i, type] : vals){
        if(type == 1)
            st.push_back({i , type});
        else{
            int d = i - st.back().first ;
            st.pop_back();
            len.push_back(d);
        }
    }
    sort(len.begin(), len.end());

    for(int i = 0; i < n; i++)
        ans += len[i] * c[i];
    cout << ans << '\n';
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
