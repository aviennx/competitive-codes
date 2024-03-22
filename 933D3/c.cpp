#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
long long int t;
    cin>>t;
    for(int w=0;w<t;w++)
    {
       
    long long   int n, m, x;
    cin>>n>>m>>x;
    x=x-1;
    set<int>sety;
    sety.insert(x);
    for(int i=0;i<m;i++)
    {
        int r;
        char s;
 
        cin>>r>>s;
 
        set<int >p;
 
        for(auto it:sety)
        {
            if(s=='0')
            {
                p.insert((it+r)%n);
            }
            else if( s=='1')
            {
                p.insert((it-r+n)%n);
            }
            else
            {
                p.insert((it+r)%n);
                p.insert((it-r+n)%n);
            }
        }
 
        swap(sety, p);
    }
 
    cout<<sety.size()<<endl;
    for(auto it : sety)
    {
        int thi= it;
       thi++;
        cout<<thi<<" ";
    }
 
    cout<<endl;
        

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


vector<int>::iterator ip;
 
    // Using std::unique
    ip = std::unique(v.begin(), v.begin() + 12);
    // Now v becomes {1 3 10 1 3 7 8 * * * * *}
    // * means undefined
 
    // Resizing the vector so as to remove the undefined
    // terms
    v.resize(std::distance(v.begin(), ip));