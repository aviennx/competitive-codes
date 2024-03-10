#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

typedef long long ll;
typedef long double ld;
#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))
#define forba(i,b,a,c) for(ll (i) = b ; (i) >= (a) ; (i)+=(c))


const int N = 2e5 + 5;

void solve1(){
    long long n, k;
    cin >> n >> k;
 
    vector<int> a(n,1);
    vector<int> b(n);
    for (int i = 0; i<n-1; ++i)
        cin >> a[i+1];
    for (int i = 0; i<n; ++i)
        cin >> b[i];
 
 
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    int x = 0;
    for (int i = n-1, j=n-1; i>=0 && j>=0; --i) {
        while (j >= 0 && a[j] >= b[i])
            j--;
        if (j>=0) {
            x++;
            j--;
        }
    }
 
    cout << n-x << endl;
}


void solve2(){
    ll int n, m;
        cin>>n>>m;
 
        vector<int> a(n), b(n);
 
        a[0] = 1;
        for(int i=1; i<n; i++)
            cin>>a[i];
 
        for(auto &e: b)     cin>>e;
 
        multiset<int> msta, mstb;
        for(auto e: a)      msta.insert(e);
        for(auto e: b)      mstb.insert(e);
 
        ll int cnt = 0;
        int sz = n;
 
        ll int ans = 0;
 
        while(msta.size())
        {
            if(sz == 1)
            {
                if(*mstb.rbegin() > *msta.begin())
                {
                    ll int x = *mstb.rbegin();
                    cnt++;
 
                    cnt = n - cnt;
 
                    if(m >= x)
                        ans = cnt*1ll*(x-1) + (cnt+1)*1ll*(m-x+1);
                    else
                        ans = cnt*1ll*m;
                }
                else
                {
                    cnt = n - cnt;
                    ans = cnt*1ll*m;
                }
 
                break;
            }
 
            if(mstb.upper_bound(*msta.rbegin()) != mstb.end())
            {
                cnt++;
                mstb.erase(mstb.upper_bound(*msta.rbegin()));
            }
 
            msta.erase(--msta.end());
            sz--;
        }
 
        cout<<ans<<"\n";
}


int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve2();
    }
    return 0;
}
