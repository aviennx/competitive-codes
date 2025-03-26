#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
        int N;
        cin>>N;
        string A;cin>>A;
        int l=0,r=0;
        for(int i=0;i<N;i++)
        {
            if(A[i]=='1')r++;
        }
        int ansi=-1,ans=1e9;
        if(r>=(N+1)/2)ansi=0,ans=N;
        for(int i=1;i<=N;i++)
        {
            if(A[i-1]=='1')r--;
            else l++;
            if(l>=(i+1)/2&&r>=(N-i+1)/2)
            {
                int t=abs(N-2*i);
                if(ans>t)ans=t,ansi=i;
            }
        }
        cout<<ansi<<"\n";
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
