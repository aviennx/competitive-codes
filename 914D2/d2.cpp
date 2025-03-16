#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

q = deque()
        for i in ind:
            while q and q[-1] <= a[i]:
                q.pop()
            while q and q[0] > b[i]:
                q.popleft()
            q.append(a[i])
            if b[i] == q[0]:
                a[i] = b[i]

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int& i : a)
        cin >> i;
    for(int& i : b)
        cin >> i;
    vector<bool> ans(n, false);
    for(int i = 0; i < 2; i++){
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(ans.begin(), ans.end());
    }

    for(int i : ans){
        if(i == false){
            cout << "No\n";
            break;
        }
    }
    cout << "Yes\n";
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