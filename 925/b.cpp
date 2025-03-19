#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    long long sum = 0;
    for(int& i : arr){
        cin >> i;
        sum += i;
    }

    long long goal = sum / n;
    long long extra = 0;
    for(int& i : arr){
        int need = goal - i;
        if(need >= 0){
            extra -= need;
            if(extra < 0){
                cout << "NO" << endl;
                return;
            }
        }else{
            extra += i - goal;
        }
    }
    cout << "YES" <<endl;

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
