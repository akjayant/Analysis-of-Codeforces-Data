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
ll T, a, b, c, d, k;
int main()
{
	read(T);
	while(T--)
	{
		read(a), read(b), read(c), read(d), read(k);
		ll tmp = a/c; if(a%c)tmp++;
		k-=tmp; 
		ll tp=b/d; if(b%d)tp++;
		if(k>=tp)cout<<tmp<<" "<<k<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}