#include <bits/stdc++.h>
using namespace std;
long long n,tmp=1,ma=0,a[1000005];
int main()
{
	cin>>n;
	for (int i=2;i<=trunc(sqrt(n));i++)
		if (n%i==0)
        {
            a[++ma]=i;
            a[++ma]=n/i;
        }
	if (ma>0)
	{
		tmp=a[1];
		for (int i=1;i<=ma;i++)
			tmp=__gcd(tmp,a[i]);
        cout<<tmp;
	}
	else cout<<n;

}
