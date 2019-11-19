#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <vector>
#include <cstdio>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
ll n,a[maxn];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    ll tmp=n,k=0;
    for(ll i=2;i<=sqrt(tmp);i++)
        if(n%i==0)
        {
            a[++k]=i;
            while(n%i==0)n/=i;
        }
    if(n!=1&&n!=tmp)a[++k]=n;
    int flag1=0,flag2=0;
    for(ll i=1;i<=k;i++)
    {
        if(a[i]%2==0)flag1=1;
        else flag2=1;
    }
    if(flag1==0&&flag2==0)cout<<n<<endl;
    else if(flag1==1&&flag2==1)cout<<1<<endl;
    else if(flag1==1&&flag2==0)cout<<2<<endl;
    else if(flag1==0&&flag2==1&&k==1)cout<<a[1]<<endl;
    else if(flag1==0&&flag2==1&&k>1)cout<<1<<endl;
    return 0;
}
