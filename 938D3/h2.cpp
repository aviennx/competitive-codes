#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N =1e7 + 5;
int lp[N] = {};
    
void starter(){
    for(int i=2;i<N;i++) {
        if(lp[i])
            continue;
        for(int j=i;j<N;j+=i) {
            if(lp[j]==0)
                lp[j] = i;
        }
    }
}
void builder(unordered_set<int>& st, int curr){

    while(curr > 1) {
            int t = lp[curr];
            while(curr % t == 0) {
                st.insert(t);
                curr /= t;
            }
        }
}
void checker(unordered_set<int>& st, int curr, int& ans){
    while(curr > 1) {
            int t = lp[curr];
            while(curr % t == 0) {
                if(st.count(t))
                    ans = max(ans, t);
                curr /= t;
            }
        }
}

void solve(){
    string a, b;
    cin >> a >> b;
    string curr;
    sort(a.begin(), a.end());
    int ans = 1;
    unordered_set<int> sta;
    do {
        curr = a;
        if(a[0] == '0')
            continue;
        int v = stoi(curr);
        builder(sta, v);

    } while (next_permutation(a.begin(), a.end()));
    sort(b.begin(), b.end());
    do {
        curr = b;
        if(curr[0] == '0')
            continue;
        int v = stoi(curr);
        checker(sta, v, ans);

    } while (next_permutation(b.begin(), b.end()));
    cout << ans << '\n';
}


int32_t main(){
    starter();
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
