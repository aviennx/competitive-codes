#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int query(int x, int y){
    printf("? %d %d\n", x, y);
    cout.flush();
    int ans;
    cin >> ans;
    cout.flush();
    return ans;
}

void print_ans(int x, int y){
    printf("! %d %d\n", x, y);
    cout.flush();
}

void solve(){
    int n, m ;
    cin >> n >> m;
    if(n == 1 && m == 1){
        print_ans(1,1);
        return;
    }
    int pd1 = query(1, 1), pd2 = n + m - 2 - query(n, m);
    int nd1 = query(1, m);
    /*
    nd1 - m + 1 = i - j
    pd1 + 2= i1 + j1
    pd2 + 2=  i2 + j2


    */
    int i1 = (nd1 + 3 + pd1 - m) / 2 , j1 = pd1 + 2 - i1;
    int i2 = (nd1 + 3 + pd2 - m) / 2, j2 = pd2 + 2 - i2;

    if( i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= m && query(i1, j1) == 0)
        print_ans(i1 ,j1);
    else
        print_ans(i2, j2);
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
