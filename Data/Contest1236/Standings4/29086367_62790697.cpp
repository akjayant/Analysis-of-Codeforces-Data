#include<bits/stdc++.h>
#define P 1000000007
using namespace std;
long long n,m;
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b%2==0) a=(a*a)%P,b/=2; 
		else res=(res*a)%P,b--;
	}
	return res%P;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	cin>>n>>m;
	long long tmp=(ksm(2,m)-1+P)%P;
	cout<<ksm(tmp,n)%P<<endl;
	return 0;
}
