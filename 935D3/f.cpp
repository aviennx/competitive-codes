#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define ll long long

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1 ; i <= n; i++)
        cin >> a[i];
    vector<int> id(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> id[i];
    priority_queue<ll,vector<ll>,greater<ll>> q;
    int ans=0,x=0;
    for(int i=n;i>=1;i--) {
       q.emplace(a[id[i]]);
       while((int)q.size() > i)
            q.pop();
       auto cnt=q.top()*min(i,(int)q.size());
       if(cnt>=ans)
            ans=cnt,x=i;
    }
    cout << ans << " " << x << '\n';
   


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