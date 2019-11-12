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
    int n;
    cin>>n;
    int i,j;
    vector<vector<int> >v(n);
    j=0;
    bool f=1;
    rep(i,0,n*n)
    {
    v[j].pb(i+1);
    if(f)
    j++;
    else
    j--;
    if(j==n)
    {
        f=0;
        j--;
    }
    if(j<0)
    {
        f=1;
        j=0;
    }
    }
    rep(i,0,n)
    {
    rep(j,0,n)
    cout<<v[i][j]<<" ";
    cout<<"\n";
    }
    return 0;
}
