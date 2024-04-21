#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
   	vector<int> arr(n);
   	for(int& i : arr)
   		cin >> i;
   	int ans = 0;
   	for(int i = 1; i <= n; i++){
   		for(int s = 0; s < n; s += i){
   			int l = s;
   			int r = min(n, s + i - 1);
   			vector<int> curr(l);
   			int cnt = 0;
   			for(int j = 0; j < l; j++)
   				curr[j] = arr[l++];
   			l = 0, r = l - 1;
   			while(l < r){
   				if(curr[l] == curr[r]){
   					l++;
   					r--;
   					continue;
   				}
   				if(arr[l] > arr[r]){
   					cnt++;
   					arr[l] -= arr[r];
   					r--;
   				}else{
   					cnt++;
   					arr[r] -= arr[l];
   					l++; 
   				}
   			}
   			ans += cnt;
   		}
   	}
   	cout << ans << '\n';


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
const int n = grid.size();
      const int m = grid[0].size();
      vector<vector<int>> tr, tl;
      tr = grid;
      tl = grid;

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (j > 0) {
            tl[i][j] = max(tl[i][j], tl[i][j - 1]);
            tr[i][m - 1 - j] = max(tr[i][m - 1 - j], tr[i][m - j];
          }
          if (i > 0) {
            tl[i][j] = max(tl[i][j], tl[i - 1][j]);
            tr[i][j] = max(tr[i][j], tr[i - 1][j]);
          }
        }
      }
auto chk = [&](int r, int c){
    int less = 0;
    ll cst = 0;

    for (auto [a, b] : A)
        if (a < med)
            less++;
    
    for (int i = A.size() - 1; i >= 0 ; i--){
        if (A[i].first < med and A[i].second and less > n / 2 - 1){
            cst += med - A[i].first;
            less--;
        }
    }
    return less <= n / 2 - 1 and cst <= k;
};

int maxsum = INT_MIN;
for (int i = n - 1; i > 0; i--) {
for (int j = 0; j < m; j++) {
  int other = INT_MIN;
  if (j > 0) {
    other = max(other, tl[i - 1][j - 1]);
  }
  if (j < m - 1) {
    other = max(other, tr[i - 1][j + 1]);
  }
  maxsum = max(maxsum, grid[i][j] + other);
}
}
