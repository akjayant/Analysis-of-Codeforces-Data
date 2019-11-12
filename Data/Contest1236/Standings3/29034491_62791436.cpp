#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
#define M 1000000007
LL mypow(LL a,LL b)
{
    LL sum=1;
    while(b)
    {
        if(b&1)
            sum=(sum*a)%M;
        a=(a*a)%M;
        b=b>>1;
    }
    return sum%M;
}
int main() {
	int a,b;
	cin>>a>>b;
	LL ans=mypow(2,b);
	ans-=1;
	ans=mypow(ans,a);
	cout<<ans<<endl;
	return 0;
}
