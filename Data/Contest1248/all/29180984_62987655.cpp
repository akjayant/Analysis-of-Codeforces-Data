#include<bits/stdc++.h>
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    long long n,m,p,M,N; 
    while(t--){
        N=0; M=0;
        cin>>n;
        for(int i=0; i<n; i++) {
        cin>>p; if (p&1) N++;        
        }
        cin>>m;
        for(int i=0; i<m; i++) {
        cin>>p; if (p&1) M++;        
        }
        cout<<M*N+(n-N)*(m-M)<<"\n";
    } 
    
    return 0;
}

