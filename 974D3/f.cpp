#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES" : "NO")

using namespace std;

string vowels = "aeiou";
    int vit(char c) {
        switch (c) {
            case 'a': return 0;
            case 'e': return 1;
            case 'i': return 2;
            case 'o': return 3;
            case 'u': return 4;
            default: return -1;
        }
    }
"iqeaouqi"
int main() {
    string S;
    int k;
    cout << "Enter the string S: ";
    cin >> S;
    cout << "Enter the value of k: ";
    cin >> k;    
    long long ans = 0;
    int n = S.length();
    vector<int> pref(n + 1, 0);
    vector<int> vmask(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(i)
            pref[i] = pref[i - 1];
        int ck = vit(S[i - 1]);
        if(ck == -1)
            pref[i]++;
        vmask[i] = vmask[i - 1];
        if (ck != -1) {
            vmask[i] ^= (1 << ck);
        }
    }
    map<int, array<int, 32>> mp;
    set<int> cnter;
    cnter.insert(0);
    mp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int c = pref[i] - k;
        if (c >= 0 && mp.count(c)) {
            for (int m = 0; m < 32; ++m) {
                if ((vmask[i] ^ m) == 31) {
                    ans += mp[c][m];
                }
            }
        }
        cnter.insert(pref[i]);
        mp[pref[i]][vmask[i]]++;
    }

    cout << "Number of substrings: " << ans << endl;

    return 0;
}