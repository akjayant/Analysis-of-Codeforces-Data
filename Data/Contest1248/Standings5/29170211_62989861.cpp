#include<bits/stdc++.h>
#define fr(i,a,b) for(register int i = a;i <= b;++i)
#define int long long
#define N 100010
using namespace std;

int a[N];

inline int read(){
	int x = 0,f = 1;char c = getchar();
	while(!isdigit(c)){if(c == '-')f = -1;c = getchar();}
	while(isdigit(c)){x = x * 10 + c - '0';c = getchar();}
	return f * x;
}

signed main(){
	int n = read(),cnt = 0,s = 0;
	fr(i,1,n)a[i] = read(),s += a[i];
	sort(a + 1,a + n + 1);
	fr(i,1,n / 2)cnt += a[i];
	s -= cnt;
	cout<<1ll * s * s + 1ll * cnt * cnt<<endl;
	return 0;
}
