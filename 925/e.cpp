#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

pair<int,int> getCnt(int x){
    int a = 0, b = 0;
    while(x != 0 && x % 10 == 0){
        x /= 10;
        a++;
    }
    while(x != 0){
        b++;
        x /= 10;
    }
    return {a,b};
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    int mindigits = m + 1;

    vector<pair<int,int>> v;
    for(int i : arr){
        v.push_back(getCnt(i));
    }
    sort(v.rbegin(), v.rend());

    int dcount = 0;
    for(int i = 0; i < n ; i++){
        if( i % 2 == 0){
            dcount += v[i].second;
        }else{
            dcount += v[i].first;
            dcount += v[i].second;
        }
    }
    //cout << dcount << endl;
    if(dcount >= mindigits){
        cout << "Sasha\n";
    }else{
        cout << "Anna\n";
    }


}


int main(){
    //reopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
