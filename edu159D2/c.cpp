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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1){
        cout<<1<<endl;
        return;
    }
    sort(a.rbegin(), a.rend());
    int x=a[0]-a[1],n1=-1e18;
    for(int i=2;i<n;i++)
        x=__gcd(x,a[i-1]-a[i]);

    for(int i=1;i<n;i++){
        if(a[i-1]-a[i]>x){
            n1=a[i-1]-x;
            break;
        }
    }
    int sum=0;
    if(n1==-1e18)
        n1=a[n - 1]-x;
    sum=(a[0]-n1)/x;
    for(int i=0;i<n;i++)
        sum+=(a[0]-a[i])/x;
    cout<<sum<<endl;
   


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
