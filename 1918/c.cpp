#include<bits/stdc++.h>
using namespace std;



void debugNum(long long x){
    int msb = 63;
    cout << x << "is number" << endl;

    while(msb >=0){
        if( (x >> msb) && 1)
            cout << msb << " ";
        msb--;
    }
    cout << " ---- " << endl;
}
void solve(){
    long long x , y, r;
    cin >> x >> y >> r;

    long long a = max(x,y);
    long long b = min(x,y);
    //cout << a << " " << b << endl;
    int msb = 63;
    //debugNum(a);
    //debugNum(b);
    long long main_val = 0;

    while( msb >=0 && ((a >> msb) & 1) == 0)
        msb--;
    while( msb >= 0 && (((a >> msb) & 1) == ((b >> msb) & 1))){
        long long val = (a >> msb ) & 1;
        a -= val << msb;
        b -= val << msb;
        msb --;
    }

    while(msb >= 0 && (((a >> msb) & 1) == 0))
        msb--;

    if(msb >=0){
        main_val = (1ll << msb);
        msb --;
    }

    long long deleter = 0;
    //debugNum(main_val);

    for(int i = msb ; i >=0 ; i--){
        long long at_a = (a >> i) & 1;
        long long at_b = (b >> i) & 1;

        if(at_a == at_b)
            continue;

        if(at_b){
            main_val -= (1ll << i);
        }else{
            long long new_deleter = deleter + (1ll << i);
            if(new_deleter <= r){
                main_val -= (1ll << i);
                deleter = new_deleter;
            }else{
                main_val += (1ll << i);
            }
        }
    }
    cout << abs(main_val) << endl;

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
