#include <bits/stdc++.h>
using namespace std;
int const mod = 998857459;
int const N = 1000100;
bool flag[N];
int prime[N],len;
int main()
{
	long long n;
	cin>>n;
	for(int i=2;i<N;i++) 
		if(!flag[i])
		{
			prime[++len]=i;
			for(int j=i+i;j<N;j+=i)
				flag[j]=1;
		}
	int num=0;
	long long hh=0;
	for(int i=1;n>=prime[i]&&i<=len;i++)
	if(n%prime[i]==0)
	{
		num++;
		hh=prime[i];
		while(n%prime[i]==0)
			n/=prime[i];
	}
	if(n!=1)
		num++,hh=n;
	if(num==1)
		cout<<hh<<endl;
	else
		cout<<1<<endl;
	return 0;
}
