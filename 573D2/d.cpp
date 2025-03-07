#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "sjfnb\n" : "cslnb\n")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n + 1);
    map<int,int> mp;
    int ok=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
        ok&=(mp[a[i]]<3);
    }
    int cnt=0;
    for(auto it:mp)
    {
        if(it.second>=2) cnt++;
    }
    ok&=(cnt<=1);
    for(auto it:mp)
    {
        if(it.second==2)
        {
            ok&=(mp.count(it.first-1)==0);
            if(it.first==0)
                ok=0;
        } 
    }
    if(!ok){
        cout << "cslnb\n";
        return;
    }
    sort(a.begin() + 1, a.end());
    int s=0;
    for(int i=1;i<=n;i++)
    {
        s+=a[i]-(i-1);
    }
    s%=2;
    if(s)
        cout << "sjfnb\n";
    else
        cout << "cslnb\n";


}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
