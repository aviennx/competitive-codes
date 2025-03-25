#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;  
 



void solve(){
    int n, m , x;
    cin >> n >> m >> x;
    set<int> poss;
    poss.insert(x - 1);
    while(m--){
        set<int> poss2;
        int d;
        char c;
        cin >> d >> c;
        if(c == '0' || c == '?'){
            for(int i : poss)
                poss2.insert((i + d) % n);
        }
        if(c == '1' || c == '?'){
            for(int i : poss)
                poss2.insert((i - d + n) % n);
        }
        poss = poss2;
    }
    cout << (int)poss.size() << '\n';
    for(int i : poss){
            cout << i + 1 << " ";
    }
    cout << '\n';
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

