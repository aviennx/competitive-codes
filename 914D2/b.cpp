#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    int it = 0;
    for(auto& i : arr){
        pair<int,int> curr;
        cin >> curr.first;
        curr.second = it++;
        i = curr;
    }
    sort(arr.begin() ,arr.end());

    vector<int> ans(n, 1);
    vector<int> pref(n);
    vector<int> reachable(n);

    for(int i = 0; i < n; i++)
        pref[i] = arr[i].first + (i ? pref[i - 1] : 0);

    for(int i = n - 1; i >= 0; i--){

        int index = arr[i].second;
        int val = pref[i];
        //cout << index << " " << val << endl;
        reachable[i] = i;
        ans[index] = i;

        if((i + 1 < n && arr[i + 1].first > val) || i == n - 1){
            continue;
        }
        int valid_upto = i + 1;
        reachable[i] = i + 1;
        ans[index] = i + 1;
        if(reachable[valid_upto] > valid_upto){
            valid_upto = reachable[valid_upto];
            reachable[i] = valid_upto;
            ans[index] = valid_upto ;
        }
    }
    for(int i : ans)
        cout << i << " ";
    cout << '\n';
   


}


int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        //cout << "_-----------------\n";
        solve();

    }
    return 0;
}
