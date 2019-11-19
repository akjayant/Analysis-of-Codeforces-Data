#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inarr(a,k,n) for(int i=k;i<n;i++){cin>>a[i];}
#define outarr(a,k,n) for(int i=k;i<n;i++){cout<<a[i]<<" ";}
#define inpair(a) cin>>a.first>>a.second
#define outpair(a) cout<<a.ff<<" "<<a.ss<<endl
#define in2(a,b) cin>>a>>b
#define in3(a,b,c) cin>>a>>b>>c
#define fastio ios_base::sync_with_stdio(false)

int main(){
    fastio;
    int t=1;
    cin>>t;
    while(t--){
        int a,b,c,d,k;
        in2(a,b);in3(c,d,k);
        c=(a+c-1)/c;d=(b+d-1)/d;
        if(c+d<=k){
            cout<<c<<" "<<d<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}
