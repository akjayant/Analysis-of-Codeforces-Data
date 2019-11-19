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
char s[N];
int n, T, ans;
int main()
{
	read(T);
	while(T--)
	{
		read(n);
		scanf("%s", s+1); ans=n;
		for(R int i=1; i<=n; i++)
		{
			if(s[i]=='1')
			{
				ans=max(ans, n*2-(i-1)*2);
				ans=max(ans, n*2-(n-i)*2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}