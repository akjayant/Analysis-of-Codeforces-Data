#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
int n, a[N];
ll ans1=0, ans2=0;

inline int read() {
	int red = 0, f_f = 1; char ch = getchar();
	while(ch>'9'||ch<'0') {if(ch == '-') f_f = -1; ch = getchar();}
	while(ch>='0'&&ch<='9') red = red * 10+ch-'0', ch = getchar();
	return red * f_f;
}

int main()
{
	n = read();
	for(int i = 0; i < n; i++) a[i] = read();
	sort(a, a+n);
	for(int i = 0; i < n/2; i++) ans1 += a[i];
	for(int i = n/2; i < n; i++) ans2 += a[i];
	printf("%lld\n", ans1*ans1 + ans2*ans2); 
	return 0;
}