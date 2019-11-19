#include<bits/stdc++.h>
#define R register
#define ll long long
using namespace std;
const int N = 2e6+200;
template <class Ruby> inline void read(Ruby &x)
{
	x=0;
	char ch=getchar(), w=0;
	while(!isdigit(ch))w=(ch=='-'), ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
	x=w?-x:x;
}
ll n, k, buc[N], val[N], l, r;
int main()
{
	read(n), read(k); l=1, r=n;
	for(R int i=1; i<=n; i++)read(val[i]), buc[i]=1;
	sort(val+1, val+1+n);
	while(k && l<r)
	{
		if(buc[l]<buc[r])
		{
			if(k>=(val[l+1]-val[l])*(buc[l]))
			{
				k-=(val[l+1]-val[l])*(buc[l]);
				buc[l+1]+=buc[l]; l++;
			}
			else 
			{
				val[l]+=(k/buc[l]);
				k=0;	
			}
		}
		else 
		{
			if(k>=(val[r]-val[r-1])*(buc[r]))
			{
				k-=(val[r]-val[r-1])*(buc[r]);
				buc[r-1]+=buc[r]; r--;
			}
			else 
			{
				val[r]-=(k/buc[r]);
				k=0;	
			}
		}
//		cout<<l<<" "<<r<<" "<<k<<endl;
	}
	cout<<val[r]-val[l];
	return 0;
}