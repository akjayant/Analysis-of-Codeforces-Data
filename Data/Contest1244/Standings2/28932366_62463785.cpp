#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ifstream fin("AAtest.in.txt");
ll a,b,c,d,k,t,x,y;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0);
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>k;
        x=(a+c-1)/c;
        y=(b+d-1)/d;
        if(k<x+y) cout<<-1<<"\n";
        else cout<<x<<" "<<y<<"\n";
    }
}
