#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")
#define fi  first
#define se second
const int N = 3e5 + 5;

pair<int,int> arr[N] = {};
pair<int,int> st[N];
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].fi >> arr[i].se;
    }
    int curr = 0;
    int ind = 0;
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++){
        int rem = 0;
        while(ind){
            if(st[ind].se == arr[i].se){
                arr[i].fi += st[ind--].fi - rem;
            }
            else if(st[ind].fi <= arr[i].fi)
                rem = max(rem, st[ind--].fi);
            else
                break;
        }
        ind++;
        st[ind] = arr[i];
        curr = max(curr, st[ind].fi);
        cout << curr << ' ';
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

