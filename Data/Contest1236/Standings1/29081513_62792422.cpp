#include<bits/stdc++.h>
#define ll long long
#define R register
using namespace std;

template <class Ruby_Rose> inline void read(Ruby_Rose &x)
{
 	x=0;
	char ch=getchar(), w=0;
	while(!isdigit(ch))w=(ch=='-'), ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
	x=w?-x:x;
}
int n, ans[310][310];
int main()
{
	read(n); int pol=0;
	for(R int i=1; i<=n; i++)
	{
		if(i&1)
		for(R int j=1; j<=n; j++)ans[j][i]=++pol;
		else
		for(R int j=n; j>=1; j--)ans[j][i]=++pol;
	}
	for(R int i=1; i<=n; i++)
	{
		for(R int j=1; j<=n; j++)printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}