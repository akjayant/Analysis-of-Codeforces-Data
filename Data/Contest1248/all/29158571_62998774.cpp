//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n,m;
int mod=1e9+7;
int32_t main()
{
    IOS;
    cin>>n>>m;
    if(n>m)
        swap(n,m);
    int base[100005];
    base[0]=2;
    base[1]=2;
    for(int i=2;i<=100003;i++)
    {
        base[i]=base[i-1]+base[i-2];
        base[i]%=mod;
    }
    int st=base[n];
    int st1=st+2;
    int st2=st1+2;
    if(m==1)
        return cout<<st%mod,0;
    if(m==2)
        return cout<<st1%mod,0;
    if(m==3)
        return cout<<st2%mod,0;
    int ad1=2;int ad2=2;
    int last=st2;
    for(int i=4;i<=m;i++)
    {
        int temp=ad1+ad2;
        last+=temp;
        ad1=ad2;
        ad2=temp;
        last%=mod;
        ad1%=mod;
        ad2%=mod;
    }
    cout<<last%mod;
}
//OEIS