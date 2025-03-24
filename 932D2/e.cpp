#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>


const int N = 2e5 + 5;


void printer(int x, int y){
    std::bitset<8> a(x);
    std::cout << a << " ";
    std::bitset<8> b(y);
    std::cout << b << '\n';
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i] >> b[i];
    }
    vector<vector<int>> strict(n ,vector<int>(32,0)), decodable(n , vector<int>(32, 0));

    for(int i = 0; i < n; i++){
        if(i){
            strict[i] = strict[i - 1];
            decodable[i] = decodable[i - 1] ;
        }
        bool dec = false;
        for(int bit = 31; bit >= 0; bit --){
            int abit = (a[i] >> bit) & 1;
            int bbit = (b[i] >> bit) & 1;
            if(abit == bbit){
                if(bbit == 1){
                    if(dec)
                        decodable[i][bit]++;
                    else
                        strict[i][bit]++;
                }
            }
            else if(bbit){
                decodable[i][bit]++;
                dec = true;
            }
        }
    }
    int q;
    cin >> q;
    /*
    for(int i = 0; i < n; i++)
        printer(a[i], b[i]);
    cout << "STRICT \n";
    for(int i = 0; i < n; i++){
        for(int j = 8; j >= 0; j--)
            cout << strict[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << "DECODABLE\n";
    for(int i = 0; i < n; i++){
        for(int j = 8; j >= 0; j--)
            cout << decodable[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    */
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = 0;
        vector<int> curr_strict(32, 0), curr_decodable(32, 0);
        for(int i = 31; i >= 0; i--){
            curr_strict[i] = strict[r][i] - (l ? strict[l - 1][i] : 0);
            curr_decodable[i] = decodable[r][i] - (l ? decodable[l - 1][i] : 0);
        }
        for(int i = 31; i >= 0; i--){
            if(curr_decodable[i] == 0 && curr_strict[i] == 0)
                continue;
            if(curr_strict[i]){
                ans |= ( 1 << i);
                if(curr_decodable[i]){
                    ans |= ((1 << i) - 1);
                    break;
                }
            }
            else if(curr_decodable[i] == 1)
                ans |= (1 << i);
            else if(curr_decodable[i] >= 2){
                ans |= (1 << i);
                ans |= ((1 << i) - 1);
                break;
            }
        }
        cout << ans << " ";
    }

    cout << '\n';


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