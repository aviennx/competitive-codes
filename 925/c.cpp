#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int& i : nums){
        cin >> i;
    }
    int ln = nums[0], rn = nums[n-1];
    int l = 0, r = n -1;
    int count_l = 0, count_r = 0;
    while(l < n && nums[l] == ln){
        l++;
        count_l++;
    }
    while(r > l && nums[r] == ln){
        r--;
        count_l++;

    }
    l = 0, r = n -1;
    while(l < n && nums[l] == rn){
        l++;
        count_r++;
    }
    while(r > l && nums[r] == rn){
        r--;
        count_r++;

    }
    int mx = max(count_l, count_r);
    cout << n - mx << endl;


    

    

}


int main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}