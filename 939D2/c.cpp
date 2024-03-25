#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES" : "NO")
const int N = 2e5 + 5;
/*
void solve(){
    int n;
    cin >> n;
    int s = 0, m;
    int cnt = 0, cnt2= 0;
    for(int i = 1; i <= n; i++){
        int add = (n + 1) * n / 2;
        int have = n * i;
        if(add <= have){
            s += have;
        }
        else{
            s += add;
            cnt++;
        }
    }
    int special = 0;
    for(int i = 1; i <= n ; i++){
        int mid = n / 2;
        int have = i * mid + (n * (n + 1)/ 2 - mid * (mid + 1)/ 2);
        int add = n * (n + 1) / 2;
        if(add > have){
            s += add;
            s -= have;
            cnt2++;
            special++;
        }
        else{
            break;
        }
    }
    int final = 0;
    if(special >= 2)
        final = 1;
    if(final){
        s -= special;
        s += (special + 1) * special / 2;
    }
    cout << s << " " << (n + cnt + special + final) << '\n';
    for(int i = 0; i < n; i++){
        cout << "1 " << (i + 1) << " ";
        for(int j = 1; j <= n; j++)
            cout << j << " ";
        cout << '\n';
    }
    for(int i = 0; i < cnt; i++){
        cout << "2 " << (i + 1) << " ";
        for(int j = 1; j <= n; j++)
            cout << j << " ";
        cout << '\n';
    }
    for(int i = 0; i < special; i++){
        cout << "1 " << (i + 1) << " ";
        for(int j = 1; j <= n; j++)
            cout << j << " ";
        cout << '\n';
    }
    if(final){
        cout << "2 " << 1 << " ";
        for(int j = 1; j <= n; j++)
            cout << j << " ";
        cout << '\n';
    }


}*/

void debug2D(vector<vector<int>>& arr){
    int N = arr.size(), M = arr[0].size();
    cout << "------------------------" << endl;
    cout << "debugging array of size N = " << N << " and M = " << M << endl;

    for(int i = 0; i < M ;i++){
        for(int j : arr[i])
            cout << j << " ";
        cout << endl;
    } 

    cout << "------------------------" << endl;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> ans;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    int s = 0, cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        cnt += 2;
            ans.push_back({1, i});
            int counter = 1;
            for(int j = 0; j < n; j++)
                mat[i][j] = counter++;
            ans.push_back({2, i});
            counter = 1;
            for(int j = 0; j < n; j++)
                mat[j][i] = counter++;
    }
    //debug2D(mat);
    for(auto& v : mat)
        for(int i : v)
            s += i;
    cout << s << " " << cnt << '\n';
    for(auto [type, rep] : ans){

            cout << type << " " << rep + 1 <<  " ";
            for(int i = 0; i < n; i++)
                cout << i + 1 << " ";
            cout << '\n';
    }
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
