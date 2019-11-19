#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=INT_MAX;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)v.size())
#define all(v) (v).begin(),(v).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define int ll
#define endl '\n'

int n,k;
int a[maxn];
int sum=0;

int cal(int l,int r)
{
    int sum1=0,sum2=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]<l) sum1+=(l-a[i]);
        else if (a[i]>r) sum2+=(a[i]-r);
    }
    return sum1+sum2;
}

int check(int x)
{
    int L=1,R=a[n]-x,ret=inff;
    while (R-L>=7)
    {
        int M=(L+R)>>1;
        int M2=M+1;
        if (cal(M,M+x)>cal(M2,M2+x)) L=M;
        else R=M2;
    }
    for(int i=L;i<=R;i++) ret=min(ret,cal(i,i+x));
    return ret;
}

int32_t main()
{
    IOS
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    sort(a+1,a+n+1);
    int L=-1,R=a[n]-a[1];
    while (R-L>1)
    {
        int M=(L+R)>>1;
        if (check(M)<=k) R=M;
        else L=M;
    }
    cout<<R<<endl;
}
