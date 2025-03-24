#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;



void print_ans(int i,int j){
    printf("! %d %d\n", i, j);
    fflush(stdout);
}

char query(int a, int b, int c, int d){
    char x;
    printf("? %d %d %d %d\n",a,b,c,d);
    fflush(stdout);
    cin >> x;
    fflush(stdout);
    return x;
 }

void solve(){
    int n;
    cin >> n;
    int j = 0, i = 0;
    for(int index = 1; index < n; index++){
        char val = query(j, j ,index, index);
        if(val == '<')
            j = index;
    }

    int best_or_with = 0;
    vector<int> poss_ans = {best_or_with};

    for(int index = 1; index < n; index++){
        char val = query(j , index, j , best_or_with);
        if(val == '>'){
            best_or_with = index;
            poss_ans.clear();
            poss_ans.push_back(index);
        }
        if(val == '=')
            poss_ans.push_back(index);
    }
    i = poss_ans[0];
    for(int index : poss_ans){
        char val = query(i, i ,index, index);
        if(val == '>')
            i = index;
    }

    print_ans(i,j);
}

int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
