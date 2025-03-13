#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
const int N=2e5+10;
const int inf=0x3f3f3f3f;
int n,a[N],b[N];
void ipt(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
}
void solve(){
    int l=inf,r=0,ans=0;
    for(int i=1;i<=n;i++) ans+=abs(a[i]-b[i]); 
    for(int i=1;i<=n;i++){
        l=min(l,max(a[i],b[i]));
        r=max(r,min(a[i],b[i]));
    }
    printf("%lld\n",ans+(2*(r-l)>0?2*(r-l):0));
}
signed main(){
    fast;
    int t;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    scanf("%lld",&t);
    while(t--){
        ipt();
        solve();
    } 
    return 0;
} 
