#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
const int N = int(1e6) + 99;
 
int nxt;
int to[N][26];
int sum[N];
long long res;
 
void add(const string& s) {
    int v = 0;
    ++sum[v];
    for (auto c : s) {
        int i = c - 'a';
        if (to[v][i] == -1)
            to[v][i] = nxt++;
        v = to[v][i];
        ++sum[v];
    }
}
 
void upd(const string& s) {
    int curLen = s.size();
    int v = 0;
    
    for (auto c : s) {
        int i = c - 'a';
        if (to[v][i] == -1) {
            res += sum[v] * 1LL * curLen;
            break;
        } else {
            int nxtV = to[v][i];
            res += (sum[v] - sum[nxtV]) * 1LL * curLen;
            --curLen;
            v = nxtV;
        }
    }
}
 
void solve(int n, vector <string> v) {
    int sumSizes = 0;
    for (int i = 0; i < n; ++i)
        sumSizes += v[i].size();
        
    nxt = 1;
    memset(sum, 0, sizeof sum);
    memset(to, -1, sizeof to);
    
    for(int i = 0; i < n; ++i) 
        add(v[i]);
    for (int i = 0; i < n; ++i) {
        reverse(v[i].begin(), v[i].end());
        upd(v[i]);
    }
}
 
int main() {
    fast;
    int n;
    cin >> n;
    vector <string> v(n);
    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    res = 0;
    solve(n, v);
    for(int i = 0; i < n; ++i)
        reverse(v[i].end(), v[i].end());
    solve(n, v);
    
    cout << res << endl;
    
    return 0;
}