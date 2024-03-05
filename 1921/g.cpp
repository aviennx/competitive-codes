#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

vector<vector<int>> rot_arr;


int n = -1, m =-1 ,k=-1;
/*

void debug(vector<vector<int>>& arr){
    int n = arr.size(), m = arr[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "__________" << endl;
}
*/
bool valid(int i ,int j){
    return i >= 0 && j >=0 && i < n  && j < m;
}
int calc(){
    //diag.resize( n, vector<int> ( m , 0));
    //upper.resize(n, vector<int> ( m , 0));
    //dp.resize(n , vector<int> ( m , 0));
    int diag[n][m]={0}, upper[n][m]={0}, dp[n][m]={0};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            upper [i][j] = rot_arr [i][j] + (i ? upper [i - 1][j] : 0);

    for(int i = 0; i < n; i++)
        for(int j = m - 1; j >= 0; j--)
            diag [i][j] = rot_arr [i][j] + ((i && j < m - 1) ? diag[i - 1][j + 1] : 0);
    
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp [i][j] = upper [i][j];
            if( i >= k){
                dp[i][j] -= upper[i - k][j];
                dp[i][j] += diag[i - k][j];
            }
            if (valid(i, j - 1))
                dp[i][j] += dp[i][j - 1];
            if( j <= k ){
                int row = i - k + j ; 
                if(row >= 0)
                    dp[i][j] -= diag[row][0];
            }else
                dp[i][j] -= diag[i][j - k];
            ans = max( ans, dp[i][j]);

        }
    }
    return ans;


}

void solve(){
    //int n, m, k;
    cin >> n >> m  >> k;
    k++ ;
    bool arr[n][m];
    rot_arr.resize(n);
    for(int i =0 ;i<n;i++){
        rot_arr[i].resize(m);
    }
    for(int i =0 ;i<n;i++){
        //arr[i].resize(m);
        //rot_arr[i].resize(m);
        char c;
        for(int j = 0; j < m; j++){
            cin >> c;
                arr[i][j] = (c=='#');
                rot_arr[i][j] = (c=='#');
        }

    }
    //debug(rot_arr);

    int ans = calc();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            rot_arr[i][j] = arr[i][m - 1 - j];
        }
    }
    //debug(rot_arr);

    ans = max(ans, calc());

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            rot_arr[i][j] = arr[n - 1- i][m - 1 - j];
        }
    }
    //debug(rot_arr);

    ans = max(ans, calc());

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            rot_arr[i][j] = arr[n - i - 1][j];
        }
    }
    //debug(rot_arr);

    ans = max(ans, calc());

    cout << ans << endl;



}


int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        //cout << test_case << " : "  << endl ;
        solve();
        //cout << "---------------------" << endl;
    }
    return 0;
}
