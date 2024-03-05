#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

void solve(){
    int h,w,xa,ya,xb,yb;
    cin>>h>>w>>xa>>ya>>xb>>yb;

    if(xb<=xa){
        cout<<"Draw"<<endl;
        return;
    }
    string winner="Draw";
    int Rgap=xb-xa-1, Cgap=abs(yb-ya);
    int aturns=1+(Rgap)/2, bturns=(Rgap+1)/2;

    if(Rgap%2==0){
        //cout<<"case1 ";
        winner="Alice";
        int dist=Cgap;
        int extra;
        if(yb==ya)
            extra=max(yb-1,w-yb);
        else if(ya<yb)
            extra=w-yb;
        else
            extra=yb-1;
        if(dist+min(bturns,extra)>aturns)
            winner="Draw";


    }else{
        //cout<<"case2 ";
        winner="Bob";
        int dist=Cgap;
        int extra;
        if(yb==ya)
            extra=max(ya-1,w-ya );
        else if(yb<ya)
            extra=w-ya;
        else
            extra=ya-1;
        if(dist+min(aturns,extra)>bturns)
            winner="Draw";
    }

    cout<<winner<<endl;



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
