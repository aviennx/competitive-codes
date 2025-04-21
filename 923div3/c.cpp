#include<bits/stdc++.h>
using namespace std;




void solve(){
    int n , m , k;
    cin >> n >> m >> k;

    vector<int> arr1(n), arr2(m);
    map<int,int> mp;

    unordered_set<int> s1, s2, common;
    for(int& i : arr1){
        cin >> i;
    }
    for(int& i : arr2)
        cin >> i;

    for(int i : arr1){
        if(i <= k)
            s1.insert(i);
    }
    for(int i : arr2){
        if(i <= k)
            s2.insert(i);
    }
    for(int i : s1){
        if(s2.find(i) != s2.end()){
            common.insert(i);
            s2.erase(i);
        }
    }
    for(int i :common)
        s1.erase(i);
    if((int)s1.size() + (int)s2.size() + (int)common.size() < k){
        cout <<"NO"<<endl;
        return;
    }
    if((int)s1.size() > k / 2|| (int)s2.size() > k/2){
        cout <<"NO"<<endl;
        return;
    }
    cout << "YES" << endl;
    return ;


    


}


int32_t main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
