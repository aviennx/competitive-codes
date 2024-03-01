#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int>cnt(2,0);
    for(int i=0; i<n; ++i)
        cnt[s[i]-'0']++;
    for(int i=0; i<n; ++i)
    {
        int x=(s[i]-'0')^1;
        if(cnt[x]==0)
        {
            cout<< n-i<<endl;
            return;
        }
        cnt[x]--;
    }
    cout<<0<<endl;

}


int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    //cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
