#include<stdio.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<time.h>
#include<map>
#include<vector>
#include<iostream>
#include<assert.h>
using namespace std;
#define sca(a) scanf("%d",&a)
#define out(a) printf("%d\n",a)
#define mes(x,a); memset(x,a,sizeof(x));
#define lowbit(x)  x & (-x)
#define pb push_back
#define mk make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pii pair<int, int>
typedef unsigned long long ull;
typedef long long ll;
const int maxn=1e5+5;
const int maxm=2e5+5;
const int inf =0x3f3f3f3f;
const ll mod=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
int m,n,w,k;
void init()
{

}
bool judge(int now)
{

}
ll quickpow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int a[maxn];
int main()
{
    ll k;
    scanf("%d %lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int l,r;
    l=1,r=n;
    ll q;
    while(1)
    {
        while(a[l+1]==a[l]&&l<r)
            l++;
        while(a[r-1]==a[r]&&r>l)
            r--;
        if(a[l]==a[r])
        {
            puts("0");
            return 0;
        }
        int siz=min(l,n-r+1);
        //printf("%d %d %lld\n",l,r,k);
        if(siz==l)
        {
            q=a[l+1]-a[l];
            q*=l;
            if(q<k)
            {
                k-=q;

                l++;
            }
            else
            {
                a[l]+=k/l;
                printf("%d\n",a[r]-a[l]);
                return 0;
            }
        }
        else
        {
            q=a[r]-a[r-1];
            q=q*(n-r+1);
            if(q<k)
            {
                k-=q;//printf("%lld\n",q);
                r--;
            }
            else
            {
                a[r]-=k/(n-r+1);
                printf("%d\n",a[r]-a[l]);
                return 0;
            }
        }
    }
}
