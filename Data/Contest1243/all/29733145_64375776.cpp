                                        ///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo
#define MOD 1000000007
#define maxn 1000111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))

using namespace std;
int a[maxn];
void nhap()
{
    int n;
    int mx=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--)
    {
        int g=min(a[i],n-i+1);
        mx=max(g,mx);
    }
    cout<<mx<<'\n';

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen(Zo".inp","r",stdin);
//    freopen(Zo".out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    nhap();
}
