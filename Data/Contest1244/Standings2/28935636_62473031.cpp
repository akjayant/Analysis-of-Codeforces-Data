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
char c[1005];
int main()
{
    int t ;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",c);
        int first=-1,second=-1;
        for(int i=0; i<n; i++)
            if(c[i]=='1')
            {
                first=i+1;
                break;
            }
        for(int i=n-1; i>=0; i--)
            if(c[i]=='1')
            {
                second=i+1;
                break;
            }
        if(first==-1)
            printf("%d\n",n);
        else
            printf("%d\n",2*max(second,n-first+1));
    }
}
