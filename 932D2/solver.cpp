#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;


string hasher(string& w){
    vector<int> cnt(26,0);
    for(char c : w)
        cnt[c - 'a']++;
    string ans;
    for(auto i : cnt)
        ans += ('0' + i);
    return ans;
}
vector<long> countSentences(vector<string> wordSet, vector<string> sentences){
    unordered_map<string, int> mp;
    for(auto& w : wordSet){
        auto h = hasher(w);
        mp[h]++;
    }
    int n = sentences.size();
    vector<long> ans(n);
    for(int i = 0; i < n; i++){
        string curr = sentences[i];
                cout << curr << endl;

        string word1, word2 ;    
        stringstream iss(curr);
        long curr_ans = 1;
        while (iss >> word1){
            word2 = word1;
            auto h = hasher(word2);
            curr_ans *= mp[h];
        }
        ans[i] = curr_ans;
    }
    return ans;

}

void solve(){
    int n;
    cin >> n;
    vector<string> wordSet(n);
    for(auto& i : wordSet){
        cin >> i;
        cout << i << endl;
    }
    int m;
    cin >> m;
    vector<string> sentences(m);
    
    for(auto& i : sentences){
        string curr;
        getline(cin , curr);
        i = curr;
        cout << i << endl;
    }

    auto ans = countSentences(wordSet, sentences);
    for(auto i : ans)
        cout << i << " ";
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
