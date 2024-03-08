#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    deque<int> a0 = {1}, b0= {1};
    if(n == 1){
        if(a == b)
            cout << 0 << '\n';
        else
            cout << 1 << " " << 1 << '\n';
        return;
    }
    if(a[0] == '0'){
        a0.push_back(1);
    }
    if(b[0] == '0'){
        b0.push_back(1);
    }

    for(int i = 2; i <= n; i++){
        if(a[i - 1] == '0')
            continue;
        if(a0.back() == i - 1){
            a0.pop_back();
            a0.push_back(i);
        }else{
            a0.push_back(i - 1);
            a0.push_back(i);
        }

    }
    for(int i = 2; i <= n; i++){
        if(b[i - 1] == '0')
            continue;
        if(b0.back() == i - 1){
            b0.pop_back();
            b0.push_back(i);
        }else{
            b0.push_back(i - 1);
            b0.push_back(i);
        }
    }
    if(a0.size() >= 2 && a0[0] == 1 && a0[1] == 1){
        a0.pop_front();
        a0.pop_front();
    }
    if(a0.size() >= 2 && b0[0] == 1 && b0[1] == 1){
        b0.pop_front();
        b0.pop_front();
    }
    cout << (int)a0.size() + (int)b0.size() << " ";
    if(a0.size() != 0)
        for (auto it = a0.begin(); it != a0.end(); ++it) 
            cout << *it << " "; 
    if(b0.size() != 0)
        for (auto it = b0.rbegin(); it != b0.rend(); ++it) 
            cout << *it << " "; 
    cout << '\n';
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
