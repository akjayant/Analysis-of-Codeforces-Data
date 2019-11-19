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
#define inpair(a) cin>>a.first>>a.ss
#define outpair(a) cout<<a.ff<<" "<<a.ss<<endl
#define in2(a,b) cin>>a>>b
#define in3(a,b,c) cin>>a>>b>>c
#define fastio ios_base::sync_with_stdio(false)
ll cst = 100000;
int main(){
    cst*=cst;
    fastio;cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int xy[2][2]={0};
        int i=0;
        while(i<n){
            ll x,y;cin>>y;
            x=-y;
            y+=cst;x+=cst;
            xy[(x%2)][(y%2)]++;
            i++;
        }
        i=0;cin>>n;ll ans=0;
        while(i<n){
            ll x,y;cin>>y;
            x=y;
            y+=cst;x+=cst;
            ans+=xy[(x%2)][(y%2)];
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}