#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n;
    cin >> n;
    char trump;
    cin >> trump;
    unordered_map<char, vector<char>> cards;
    for(int i = 0 ; i < 2 * n; i++){
        string c;
        cin >> c;
        cards[c[1]].push_back(c[0]);
    }
    for(auto& [i , v] : cards)
        sort(v.rbegin() , v.rend());

    vector<string> ans;

    for(auto& [suit, numbers] : cards){
        if(suit == trump)
            continue;
        while(!numbers.empty()){
            string first = "";
            first += numbers.back();
            first += suit;
            string second= "";
            ans.push_back(first);
            numbers.pop_back();
            if(numbers.empty()){
                if(cards[trump].empty()){
                    cout << "IMPOSSIBLE\n";
                    return;
                }
                second += numbers.back() ;
                second += suit;
                ans.push_back(second);
                cards[trump].pop_back();
            }else{
                second += numbers.back();
                second += suit;
                numbers.pop_back();
            }

        }
    }
    while(!cards[trump].empty()){
            string first = "";
            first += cards[trump].back();
            first += trump;
            string second = "";
            ans.push_back(first);
            cards[trump].pop_back();
            if(cards[trump].empty()){
                cout << "IMPOSSIBLE\n";
                return;
            }
            second += cards[trump].back();
            second += trump;
            ans.push_back(second);
            cards[trump].pop_back();
    }
    for(int i = 0; i < 2 * n; i += 2){
        cout << ans[i] << " " << ans[i+1] << endl;
    }

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
