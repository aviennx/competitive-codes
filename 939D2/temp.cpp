//  ॐ
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define vi vector<int>
#define  ff first
#define ss second
#define pll pair<ll,ll>
#define vll vector<ll>

const ll f = 998244353;
const ll p = 31;


const ll N = 2e6 + 1;

ll fx(vector<ll> &v) {
    ll ans=0;
    for(ll i = 0; i < 4; i++) {
        for(ll j = i+1; j < 4; j++) {
            ans = max( ans , v[i] + v[j]);
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<ll> isprime(N, 1), lp(N);
    for(ll i=2;i<N;i++) {
        if(isprime[i]==0)   
            continue;
        lp[i] = i;
        for(ll j=2*i;j<N;j+=i) {
            isprime[j] = 0;
            if(lp[j]==0)
                lp[j] = i;
        }
    }

    vector<ll> sums(N);
    for(ll i = 1; i < N; i++) {
        ll sum = 0, curr = i;
        while(curr != 1) {
            ll t = lp[curr];
            while(curr % t == 0) {
                curr /= t;
                sum += 1;
            }
        }
        sums[i] = sum;
    }

    ll t=1;
    cin>>t;
    while(t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> a(n + 1),vv(n+1);
        ll ma = 0, sum = 0;
        for(ll i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
            vv[i] = sums[a[i]];
        }
        sort(vv.begin(), vv.end());
        ll ans = sum - vv[n] - vv[n-1] ;
        ll m_take = 0;
        vector<ll> ma_val(31,-1);
        for(ll i = m; i >= max(1LL , m-40) ; i--) {
            if(ma_val[sums[i]] == -1)
                ma_val[sums[i]] = i;
        }
        for(ll i = 0; i < 31; i++) {
            ll x = ma_val[i];
            if (x == -1) {
                continue;
            }
            if(k==1) {
                ans = max(ans , sum + x - max(i, vv[n-1])) - vv[n];
                continue;
            }

            m_take = max ( m_take , x);
            vector<ll> v2 = {vv[n], vv[n-1], i, i};
            ll sum1 = sum + x + m_take * (k-1);
            ans = max( ans , sum1 - fx(v2));

            for(ll j = i+1; j < 31; j++) {
                ll y = ma_val[j];
                if (y == -1) {
                    continue;
                }
                vector<ll> v1 = {vv[n], vv[n-1], i, j};
                ll sum1 = sum + x + y + m_take * (k-2);
                ans = max( ans , sum1 - fx(v1));
            }
    
        }
        cout << ans <<"\n";
    }
}