#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    unordered_map<int,int> mpa, mpb;
    vector<int> ansa, ansb;
    int ak = 2 * k, bk = 2 * k;
    for(int& i : a){
        cin >> i;
        mpa[i]++;
        if(mpa[i] == 2 && ak >= 2){
            ak -= 2;
            ansa.push_back(i);
            ansa.push_back(i);
        }


    }
    for(int& i : b){
        cin >> i;
        mpb[i]++;
        if(mpb[i] == 2 && bk >= 2){
            bk -= 2;
            ansb.push_back(i);
            ansb.push_back(i);
        }
    }

    for(auto [val, count] : mpa){
        if(ak == 0)
            break;
        if(count == 1){
            ansa.push_back(val);
            ansb.push_back(val);
            ak--;
        }
    }

    for(int i : ansa)
        cout << i << " ";
    cout << '\n';
    for(int i : ansb)
        cout << i << " ";
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
