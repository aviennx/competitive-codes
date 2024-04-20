#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, m;
        cin >> n >> m;
        vector<int> a(n+m+1);
        vector<int> b(n+m+1);
        for(int i=0; i<n+m+1; i++){
            cin >> a[i];
        }
        for(int i=0; i<n+m+1; i++){
            cin >> b[i];
        }
        int prog = n;
        int test = m;
        int ambg = -1;
        vector<int> job(n+m+1);
        int total_skill = 0;

        for(int i=0; i<n+m+1; i++){
            if(prog && test){
                if(a[i]>b[i]){
                    job[i] = 0;
                    prog--;
                    total_skill+=a[i];
                }else{
                    job[i] = 1;
                    test--;
                    total_skill+=b[i];
                }
            }else if(prog){
                if(b[i]>=a[i] && ambg == -1){
                    ambg = i;
                    job[i] = 2;
                }else{
                    job[i] = 0;
                    prog--;
                    total_skill+=a[i];
                }
            }else if(test){
                if(a[i]>b[i] && ambg == -1){
                    ambg = i;
                    job[i] = 2;
                }else{
                    job[i] = 1;
                    test--;
                    total_skill+=b[i];
                }
            }
        }
        if(ambg == -1){
            ambg = n+m;
            job[n+m] = 2;
        }
 
        for(int i=0; i<n+m+1; i++){
            if(job[i] == 0){
                cout << total_skill - a[i] + a[ambg] << " ";
            }else if(job[i] == 1){
                cout << total_skill - b[i] + b[ambg] << " ";
            }else{
                cout << total_skill << " ";
            }
        }
        cout << endl;
   


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
