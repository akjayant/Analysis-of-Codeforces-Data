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
int T, a, b, c;
int main()
{
	read(T);
	while(T--)
	{
		read(a), read(b), read(c); int ans=0;
		while(b && c>=2)
		{
			b--, c-=2; ans+=3;
		}
		while(a && b>=2)
		{
			a--; b-=2; ans+=3;
		}
		cout<<ans<<endl;
	}
	return 0;
}