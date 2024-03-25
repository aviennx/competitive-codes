#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

int n, arr[20], mex[20];
vector<pii> ops;

void setmex(int l, int r){
    memset(mex, 0 , sizeof(mex));
    for(int i = l ; i <= r; i++){
        if(arr[i] <= n)
            mex[arr[i]]++;
    }
    int curr_mex = 0;
    while(mex[curr_mex] != 0)
        curr_mex++;
    for(int i = l; i <= r; i++)
        arr[i] = curr_mex;
    ops.push_back({l, r});
}

void build(int l ,int r){
    if(l == r){
        if(arr[l] != 0)
            setmex(l , r);
        return;
    }
    build(l, r - 1);
    if(arr[r] != r - l){
        setmex(l, r);
        build(l, r - 1);
    }
}

void solve(){
    ops.clear();
    memset(arr, 0 , sizeof(arr));
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int tot = 1 << n;
    int build_for = -1;
    int best_sum = 0;

    for(int check_for = 0; check_for < tot; check_for++){
        int curr_sum = 0;
        for(int i = 0; i < n; i++){
            if((check_for >> i) & 1){
                int l = i, r = i;
                while(r + 1 < n && (check_for >> (r + 1)) & 1)
                    r++;
                i = r;
                curr_sum += (r- l + 1) * (r- l + 1);
            }else
                curr_sum += arr[i];
        }
        if(curr_sum > best_sum){
            best_sum = curr_sum;
            build_for = check_for;
        }
    }
    //cout << best_sum << " " << build_for << '\n';
    for(int i = 0; i < n ; i++){
        if((build_for >> i) & 1){
                int l = i, r = i;
                while(r + 1 < n && (build_for >> (r + 1)) & 1)
                    r++;
                i = r;
                build(l , r);
                setmex(l , r);
        }
    }


    cout << best_sum << " " << ops.size() << '\n';
    for(auto [ l ,r ]: ops){
        cout << l + 1 << " " << r + 1 << '\n';
    }



}


int32_t main(){
    fast;
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    //cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
      //  cout << " TEST _ CASE " << test_case << '\n';

        solve();
    }
    return 0;
}
