#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n;
    cin>>n;
    vector<int>v(31,0);
    for(int i=0; i<n; ++i)
    {
        int t,x;
        cin>>t>>x;
        if(t==1)
            v[x]++;            
        else
        {
            for(int j=29; j>=0; --j)
            {
                int mx= min(x>>j,v[j]);
                x -= (mx << j);
            }
            cout<<(x==0 ? "YES" : "NO")<<endl;
        }
    }


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
