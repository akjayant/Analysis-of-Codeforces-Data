#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define Fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
int main()
{
    Fast;
    ll n,m;
    cin>>n>>m;
    ll M=1e9+7;
    if(n>m)
    {
        ll t=n;
        n=m;
        m=t;
    }
    if(n==1 && m==1)
    {
        cout<<2;
        return 0;
    }
    ll rt[m][2][2];
    for(int i=0;i<m;++i)
        rt[i][0][0]=rt[i][1][0]=rt[i][0][1]=rt[i][1][1]=0;
    rt[1][0][0]=1;
    rt[1][1][0]=1;
    rt[1][0][1]=1;
    rt[1][1][1]=1;
    for(int i=2;i<m;++i)
    {
        rt[i][1][1]=rt[i-1][1][0];
        rt[i][1][0]=(rt[i-1][0][1]+rt[i-1][0][0])%M;
        rt[i][0][1]=(rt[i-1][1][1]+rt[i-1][1][0])%M;
        rt[i][0][0]=rt[i-1][0][1];
    }
    ll er=0;
    er=(rt[m-1][0][0]+rt[m-1][0][1]+rt[m-1][1][0]+rt[m-1][1][1]-2+M)%M;
    if(n>1)
        er+=(rt[n-1][0][0]+rt[n-1][0][1]+rt[n-1][1][0]+rt[n-1][1][1])%M;
    else
        er+=2;
    cout<<(er%M);
}