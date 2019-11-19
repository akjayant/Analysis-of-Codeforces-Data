#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=1e9+7;
ll a[100005];
int main()
{
	a[0]=0;
    a[1]=2;
    a[2]=2;
    for(int i=3;i<=100000;i++){
    	a[i]=(a[i-1]+a[i-2])%p;
    }
    for(int i=2;i<=100000;i++){
    	a[i]=(a[i]+a[i-1])%p;
    }
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%lld\n",(a[n-1]+a[m-1]+2)%p);
}