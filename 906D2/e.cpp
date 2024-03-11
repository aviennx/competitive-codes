// LUOGU_RID: 156518717
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second 
const int N=2e5+5;
int n,m,k;
int f1[N],f2[N],val[N],cnt1[N];
struct node{int l,r;}a[N];
bool cmp(node a,node b){if(a.l==b.l)return a.r<b.r;return a.l<b.l;}
signed main(){

    std::iostream::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int T;cin>>T;
    while(T--){
        int ans=0,s=0;cin>>n>>m>>k;
        for(int i=1;i<=n;i++) val[i]=0;
        for(int i=1;i<=m;i++){
            cin>>a[i].l>>a[i].r;
            val[a[i].l]++,val[a[i].r+1]--;
        }
        sort(a+1,a+m+1,cmp);
        for(int i=1;i<=n;i++) val[i]+=val[i-1];
        for(int i=1;i<=n;i++) s+=(val[i]==0);
        for(int i=1;i<=n;i++) f1[i]=f1[i-1]+(val[i]==1);
        for(int i=1;i<=n;i++) f2[i]=f2[i-1]+(val[i]==2);
        for(int i=1;i<=m;i++) cnt1[i]=f1[a[i].r]-f1[a[i].l-1];
        sort(cnt1+1,cnt1+m+1,greater<int>());
        ans=s+cnt1[1]+cnt1[2];
        int j=1;
        priority_queue<pii,vector<pii>,greater<pii> >q;
        for(int i=1;i<=n;i++){
            while(!q.empty()){
                if(q.top().fi<i) q.pop();
                else break;
            }
            while(j<=m){
                if(a[j].l==i) q.push({a[j].r,j}),j++;
                else break;
            }
            if(val[i]!=2) continue;
            int id1=q.top().se;q.pop();
            int id2=q.top().se;
            ans=max(ans,s+f2[min(a[id1].r,a[id2].r)]-f2[max(a[id1].l,a[id2].l)-1]+f1[a[id1].r]-f1[a[id1].l-1]+f1[a[id2].r]-f1[a[id2].l-1]);
            q.push({a[id1].r,id1});
        }
        cout<<ans<<'\n';
    }

    return 0;
}