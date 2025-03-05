#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+2,0) , d(n+2,0);

    vector<int> dead(n + 2, 0);

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
        cin >> d[i];

    vector<int> prev(n + 2, 0), next(n + 2, 0);


    for(int i = 1; i < n; i++){
        prev[i + 1] = i;
        next[i] = i + 1;
    }

    vector<int> die;

    for( int i = 1; i <= n; i++)
        if( a[i - 1] + a[i + 1] > d[i])
            die.push_back(i);

    for(int i = 1; i <= n; i++){
        cout << die.size() << " \n"[i == n];
        
        set<int> changed;

        for( int i : die){
            dead[i] = true;
            changed.insert(prev[i]);
            changed.insert(next[i]);
            if( next[i] != 0 && prev[i] != 0){
                int l = prev[i], r = next[i];
                next[l] = r;
                prev[r] = l;
            }else if(next[i] != 0){
                prev[next[i]] = 0;
            }else if(prev[i] != 0){
                next[prev[i]] = 0;
            }
        }

        changed.erase(0);

        vector<int> Ndie;

        for(int i : changed){
            if(dead[i])
                continue;
            if(a[prev[i]] + a[next[i]] > d[i])
                Ndie.push_back(i);
        }

        die = Ndie;

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
