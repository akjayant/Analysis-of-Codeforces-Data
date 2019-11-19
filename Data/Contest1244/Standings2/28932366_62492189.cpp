#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ifstream fin("AAtest.in.txt");
ll n,p,w,d,k,q,vah;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0);
    cin>>n>>p>>w>>d;
    if((w*n)<p){
        cout<<-1;
        return 0;
    }
    k=p/w;
    q=k-d-5;
    if(q<0) q=0;
    for(ll i=k; i>=q; i--){
        vah=p-w*i;
        if(((vah/d)+i)>n) break;
        if((vah%d)==0){
            cout<<i<<" "<<vah/d<<" "<<n-i-(vah/d);
            return 0;
        }
    }
    cout<<-1;
}
