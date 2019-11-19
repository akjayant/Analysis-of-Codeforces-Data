#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll n,zz=-1;
void check()
{
	while(n>1&&zz!=-1)
	{
		if(n%zz==0)
		n/=zz;
		else
		break;
	}
	if(n!=1)
	cout<<1<<endl;
	else
	cout<<zz<<endl;
}
int main()
{
	cin>>n;
	bool flag1=1;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			zz=i;
			flag1=0;
			break;
		}
	}
	if(flag1==1)
	{
		cout<<n<<endl;
		return 0;
	}
	check();
	return 0;
}