#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<pii> reached(n + 1), rev_reached(n + 2);
    map<pii, vector<int>> mp;
    map<pii, vector<int>> rmp;
    reached[0] = {0, 0};
    rev_reached[n + 1] = {0, 0};
    mp[{0, 0}].push_back(0);
    rmp[{0, 0}].push_back(0);
    int x = 0, y = 0;

    for(int i = 0; i < n; i++){
        x += ((s[i] == 'R') - (s[i] == 'L'));
        y += ((s[i] == 'U') - (s[i] == 'D'));
        mp[{x,y}].push_back(i + 1);
        reached[i + 1] = {x, y};
    }
    x = 0, y = 0;

    for(int i = n - 1; i >= 0; i--){
        x += ((s[i] == 'R') - (s[i] == 'L'));
        y += ((s[i] == 'U') - (s[i] == 'D'));
        rmp[{x,y}].push_back(i + 1);
        rev_reached[i + 1] = {x, y};
    }
    for (auto &v : rmp){
        sort(rmp[v.first].begin(), rmp[v.first].end());
    }
    while(q--){
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        bool yes = false;

        auto it = mp[{x, y}].begin();
        if(it != mp[{x, y}].end() && (*it) < l)
            yes = true;

        if(mp[{x, y}].size() && !yes){
            it = mp[{x , y}].end();
            it--;
            if(*it > r)
                yes = true;
        }

        x += (rev_reached[r + 1].first - reached[l - 1].first);
        y += (rev_reached[r + 1].second - reached[l - 1].second);

        it = lower_bound(rmp[{x, y}].begin() ,rmp[{x, y}].end(), l) ;

        if(it != rmp[{x, y}].end() && *it <= r)
            yes = true;

        if(yes)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return;
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
