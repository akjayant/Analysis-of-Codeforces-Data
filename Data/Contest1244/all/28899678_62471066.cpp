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
        int n;cin>>n;
        string s;cin>>s;
        int i=0;int a=n,b=-1;
        while(i<n){
            if(s[i]=='1'){b=max(b,i);a=min(a,i);}i++;
        }
        b++;a=n-a;
        cout<<max(n,max(2*b,2*a))<<endl;
    }
    return 0;
}
