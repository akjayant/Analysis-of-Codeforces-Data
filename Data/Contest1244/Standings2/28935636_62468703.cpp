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
const int maxn=1e7+5;
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
int main()
{
    int t ;
    scanf("%d",&t);
    int a,b,c,d,k;
    while(t--)
    {
        cin>>a>>b>>c>>d>>k;
        int x,y;
        x=(a-1)/c+1;
        y=(b-1)/d+1;
        if(x+y>k)
            puts("-1");
        else
            printf("%d %d\n",x,y);
    }
}
