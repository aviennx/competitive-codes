#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")


#define ll long long
#define N 2000006
#define bug(a) cout << #a << " : " << a << "\n";
 
bool cmp(string &a, string &b)
{
    return a.size() < b.size();
}
 
void solve()
{
    ll n;
    cin >> n;
    vector<string> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
 
    sort(arr.begin(), arr.end(), cmp);
 
    map<pair<ll, ll>, ll> freq;
    ll ans = n;
 
    for (auto s : arr)
    {
 
        ll x = s.size();
 
        for (ll m = 1; m <= x; m++)
        {
            if ((m + x) % 2 != 0)
                continue;
 
            ll mid = (m + x) / 2;
 
            ll sum = 0;
 
            for (ll i = 0; i < mid; i++)
                sum += (s[i] - '0');
            for (ll i = mid; i < x; i++)
                sum -= (s[i] - '0');
 
            if (sum >= 0)
                ans += freq[{m, sum}];
        }
 
        reverse(s.begin(), s.end());
 
        for (ll m = 1; m <= x; m++)
        {
            if ((m + x) % 2 != 0)
                continue;
 
            ll mid = (m + x) / 2;
 
            ll sum = 0;
 
            for (ll i = 0; i < mid; i++)
                sum += (s[i] - '0');
            for (ll i = mid; i < x; i++)
                sum -= (s[i] - '0');
 
            if (sum >= 0)
                ans += freq[{m, sum}];
        }
 
        ll sum = 0;
 
        for (ll i = 0; i < x; i++)
        {
            sum += (s[i] - '0');
        }
 
        freq[{x, sum}]++;
    }
 
    cout << ans << "\n";
}
 

int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    //cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
