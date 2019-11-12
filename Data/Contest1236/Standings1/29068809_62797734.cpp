#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;


typedef long long ll;
ll bp(ll a, ll b, ll m=1e9+7){
	ll ans = 1;
	while(b > 0){
		if(b & 1){
			ans = ans * a % m;
		}
		a = a * a % m;
		b >>= 1;
	}
	return ans;
}
struct oo{
    int wa,wei;
}a[100000];
int flag[100000];
int cmp(oo aa,oo bb){return aa.wa>bb.wa;}



int main()
{
    int n;scanf("%d",&n);
    int st=n*n;int fi=n*n-n+1;
    for (int i=1;i<=n*n;++i){
        a[i].wa=0;a[i].wei=i;
    }
    for(int round=1;round<=n;++round)
    {
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;++i)
        {
            a[i].wa+= (st+fi)*n/2;
            a[i].wa-= (st-i);
            flag[st-i+1]=a[i].wei;
        }
        st-=n;fi-=n;
    }
    for (int j=1;j<=n;++j,printf("\n"))
    for (int i=1;i<=n*n;++i)
        if (flag[i]==j)
            printf("%d ",i);

}
