#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 
#define ll long long

 


void solve(){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> pre(n);
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            sum += a[i];
            pre[i] = sum;
        }
        int q;
        cin >> q;
        while(q--)
        {
            int l, u;
            cin >> l >> u;
            --l;
            int prv = (l - 1 < 0 ? 0 : pre[l-1]);
            auto it = upper_bound(pre.begin(), pre.end(), prv + u);
            if(it == pre.end())
            {
                cout << n << ' ';
                continue;
            }

            int extra = *it - prv - u;
            
            int ans1 = u * (u + 1) / 2 - extra * (extra - 1) / 2, ind1 = it - pre.begin();

            if(ind1 == l)
            {
                cout << ind1 + 1 << ' ';
                continue;
            }
            --it;
            int rem = u - (*it - prv);
            int ans2 = u * (u + 1) / 2 - rem * (rem + 1) / 2;
            cout << (ans1 > ans2 ? ind1 + 1 : ind1) << ' ';
        }
    cout << '\n';

}


int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
