#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll ans=0;
        ll od=0; ll ev=0;
        for(int i=0;i<n;i++){
            int a; cin>>a;
            if(a&1)od++;
            else ev++;
        }
        int m; cin>>m;
        for(int i=0;i<m;i++){
            int a; cin>>a;
            if(a&1)ans+=od;
            else ans+=ev;
        }
        cout<<ans<<"\n";
    }
}
