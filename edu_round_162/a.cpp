#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;


void solve(){

    int n;
    cin >> n;
    vector<int> arr(n);


    for(int& i : arr)
        cin >> i;

    int l = 0 , r = n - 1 , count = 0;

    for(int i : arr)
        count += (i==1);

    while(l < n){
        if(arr[l] == 1)
            break;
        l++;
    }

    while(0 <= r){
        if(arr[r] == 1)
            break;
        r--;
    }

    if(count == 0){
        cout << 0 << endl;
        return;
    }else{
        cout << r - l + 1 - count << endl;
        return;
    }

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
