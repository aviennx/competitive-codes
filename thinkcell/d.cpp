#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;
    for(int i = 0; i < n ;i++){
        for(int j = i; j < n; j++){
            string curr = s.substr(i , j - i + 1);
            int len = j - i + 1;
            vector<int> have_one(len , 0);
            for(int index = 0; index < len ; index ++){
                if(curr[index] == '0' || (index > 0 && have_one[index - 1]) || have_one[index]){
                    continue;
                }
                ans ++;
                have_one[index] = 1;
                if(index + 1 < n)
                    have_one[index + 1] = 1;
            }
        }
    }
    cout << ans << endl;
}


int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
