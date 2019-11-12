#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimization("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target ("avx2,avx,fma")
#define ll long long int
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for(i=l;i<r;i++)
#define bep(i,l,r) for(i=l;i>=r;i--)
#define ld long double
#define ff first
#define ss second
#define pii pair<int,int>
#define pi 3.1415926535897932384626433832
#define mod 1000000007
int main()
{
    io;
    int i,t;
    cin>>t;
    rep(i,0,t)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int j,k;
        int ans=0;
        rep(j,0,a+1)
        rep(k,0,c/2+1)
        if(b>=2*j+k)
            ans=max(ans,3*(j+k));
        cout<<ans<<"\n";
    }
    return 0;
}
