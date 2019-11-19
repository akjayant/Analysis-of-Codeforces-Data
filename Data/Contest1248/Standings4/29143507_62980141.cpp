#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
int main( ) {
    int t;cin>>t;
    while(t--){
        int n,m,e=0,o=0;
        cin>>n;
        int x[n];
        for(int i = 0 ; i < n; i ++){
            cin>>x[i];
            if(abs(x[i])%2==0)e++;
            else o++;
        }
        cin>>m;
        int y[m];
        ll ans=0;
        for(int i = 0 ; i < m; i ++){
            cin>>y[i];
            if(abs(y[i])%2==0)ans+=e;
            else ans+=o;
        }
        cout<<ans<<endl;
    }

}


