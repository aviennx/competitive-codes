#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define ll long long
const int N = 2e5 + 5;

vector<int> v;

ill f(ll n){
    if(n%4==0) return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    return 0;
}
ll h(ll n){
    ll r=n%8;
    if(r/2==0) return n;
    if(r/2==1) return 2;
    if(r/2==2) return n+2;
    return 0;
}
ll solve(ll n,ll m){
    if(n<=0||m<=0) return 0;
    return h(n)^h(n+m)^h(m);
}
int main() {
    FASTIO;
    int _;
    cin>>_;
    while(_--){
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        ll ans=0;
        ans^=f(x-1)^f(n-x)^f(y-1)^f(m-y);
        //cout<<ans<<"?";
//      ans^=solve(n-x,m-y);
//      ans^=solve(x-1,m-y);
//      cout<<ans<<"?";
        ans^=solve(n-x,m-y)^solve(x-1,m-y)^solve(x-1,y-1)^solve(n-x,y-1);
        cout<<ans<<'\n';
    } 
    return 0;
}