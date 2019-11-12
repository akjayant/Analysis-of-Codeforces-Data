#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
const int maxn=1e5+10;
//int a[maxn];
long long quickp(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b%2)
            ans=ans*a%M;
        a=a*a%M;
        b/=2;
    }
    return ans;
}
int main()
{
    long long n,m;
    scanf("%I64d%I64d",&n,&m);
    printf("%I64d\n",quickp((quickp(2,m)-1),n));
    return 0;
}
