#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    string  s;
    cin >> s;
    int h = 0, m = 0;
    h = (s[0] - '0') * 10 + (s[1] - '0');
    m = (s[3] - '0') * 10 + (s[4] - '0');
    string time = "00:00";
    string day;
    int h2;
    if(h <= 12)
        h2 = h;
    else
        h2 = h - 12;
    if(h == 0)
        h2 = 12;
    if(h <= 11)
        day = "AM";
    else
        day = "PM";
    if(m < 10){
        time[4] = (m + '0');
    }else{
        time[4] = (m % 10 + '0');
        time[3] =( m / 10 + '0');
    }
    if(h2 < 10){
        time[1] = (h2 + '0');
    }else{
        time[1] = (h2 % 10 + '0');
        time[0] =( h2 / 10 + '0');
    }
    cout << time << " " << day;
    cout << endl;
   


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
