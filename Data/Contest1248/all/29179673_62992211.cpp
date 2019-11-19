#include<bits/stdc++.h>
#define P 1000000007
using namespace std;
long long n, m, f[100005];

inline int read() {
	int red = 0, f_f = 1; char ch = getchar();
	while(ch>'9'||ch<'0') {if(ch == '-') f_f = -1; ch = getchar();}
	while(ch>='0'&&ch<='9') red = red * 10+ch-'0', ch = getchar();
	return red * f_f;
}

int main()
{
	n = read(), m = read(), f[1] = 1, f[2] = 2;
	for(int i = 3; i <= max(n, m); i++)
		f[i] = (f[i-1] + f[i-2]) % P;
	printf("%lld\n", ((f[n]+f[m])*2%P+P-2)%P);
	return 0;
}