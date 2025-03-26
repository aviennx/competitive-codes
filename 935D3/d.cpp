#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
   int n,k; cin >> n >> k;
    
    vector<int>a(n);
    for(auto &x : a) cin >> x;
    
    vector<int>b(n);
    for(auto &x : b) cin >> x;
    
    int temp=0;
    int ans=LLONG_MAX;
    for(int i=n-1;i>=0;i--){
        if(i+1<=k){
            ans=min(ans,temp+a[i]);
        }
        temp+=min(a[i],b[i]);
    }
    cout<<ans<<endl;



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
