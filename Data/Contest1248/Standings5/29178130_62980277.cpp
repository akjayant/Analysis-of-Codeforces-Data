#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll t,i,n,m;
    cin>>t;
    while(t--){
        cin>>n;
        ll u,v,od1=0,ev1=0,od2=0,ev2=0;
        for(i=0;i<n;i++){
            cin>>u;
            if(u%2) od1++;
            else ev1++;
        }
        cin>>m;
        for(i=0;i<m;i++){
            cin>>u;
            if(u%2) od2++;
            else ev2++;
        }
        cout<<(od2*od1)+(ev2*ev1)<<endl;
    }
    return 0;
}