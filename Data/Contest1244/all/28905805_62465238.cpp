#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        //ll i,j,k,n,m,x,y,ans=0,b;
        ll a,b,c,d,k,pn,pc;
        cin>>a>>b>>c>>d>>k;

        pn = a/c;
        if(a%c) pn++;

        pc = b/d;
        if(b%d) pc++;

        if(pn+pc<=k)    cout<<pn<<" "<<pc<<endl;
        else cout<<-1<<endl;
    }


}
